#include "HepMC3Wrap.h"
#include <memory>
#include <unordered_map>

// Global storage for shared pointers to maintain ownership
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenParticle>> particle_store;
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenVertex>> vertex_store;

// Implementation of the C-style interface
extern "C" {
    void* create_fourvector(double x, double y, double z, double t) {
        return new HepMC3::FourVector(x, y, z, t);
    }

    void* create_genevent(int units) {
        return new HepMC3::GenEvent(static_cast<HepMC3::Units::MomentumUnit>(units));
    }

    void* create_particle(void* momentum, int pdg_id, int status) {
        auto* mom = static_cast<HepMC3::FourVector*>(momentum);
        // Create particle with shared ownership
        auto particle = std::make_shared<HepMC3::GenParticle>(*mom, pdg_id, status);
        void* ptr = particle.get();
        // Store the shared_ptr
        particle_store[ptr] = particle;
        return ptr;
    }

    void* create_vertex() {
        auto vertex = std::make_shared<HepMC3::GenVertex>();
        void* ptr = vertex.get();
        // Store the shared_ptr
        vertex_store[ptr] = vertex;
        return ptr;
    }

    void add_particle_in(void* vertex, void* particle) {
        auto v_it = vertex_store.find(vertex);
        auto p_it = particle_store.find(particle);
        if (v_it != vertex_store.end() && p_it != particle_store.end()) {
            v_it->second->add_particle_in(p_it->second);
        }
    }

    void add_particle_out(void* vertex, void* particle) {
        auto v_it = vertex_store.find(vertex);
        auto p_it = particle_store.find(particle);
        if (v_it != vertex_store.end() && p_it != particle_store.end()) {
            v_it->second->add_particle_out(p_it->second);
        }
    }

    void set_vertex_status(void* vertex, int status) {
        auto v_it = vertex_store.find(vertex);
        if (v_it != vertex_store.end()) {
            v_it->second->set_status(status);
        }
    }

    int vertex_status(void* vertex) {
        auto v_it = vertex_store.find(vertex);
        if (v_it != vertex_store.end()) {
            return v_it->second->status();
        }
        return 0;
    }

    void add_vertex_to_event(void* event, void* vertex) {
        auto* evt = static_cast<HepMC3::GenEvent*>(event);
        auto v_it = vertex_store.find(vertex);
        if (v_it != vertex_store.end()) {
            evt->add_vertex(v_it->second);
        }
    }

    int particle_pid(void* particle) {
        auto p_it = particle_store.find(particle);
        if (p_it != particle_store.end()) {
            return p_it->second->pid();
        }
        return 0;
    }

    int particle_status(void* particle) {
        auto p_it = particle_store.find(particle);
        if (p_it != particle_store.end()) {
            return p_it->second->status();
        }
        return 0;
    }

    void* particle_momentum(void* particle) {
        auto p_it = particle_store.find(particle);
        if (p_it != particle_store.end()) {
            return new HepMC3::FourVector(p_it->second->momentum());
        }
        return nullptr;
    }

    void set_particle_status(void* particle, int status) {
        auto p_it = particle_store.find(particle);
        if (p_it != particle_store.end()) {
            p_it->second->set_status(status);
        }
    }

    void set_particle_momentum(void* particle, void* momentum) {
        auto p_it = particle_store.find(particle);
        if (p_it != particle_store.end()) {
            auto* mom = static_cast<HepMC3::FourVector*>(momentum);
            p_it->second->set_momentum(*mom);
        }
    }

    double fourvector_px(void* v) {
        return static_cast<HepMC3::FourVector*>(v)->px();
    }

    double fourvector_py(void* v) {
        return static_cast<HepMC3::FourVector*>(v)->py();
    }

    double fourvector_pz(void* v) {
        return static_cast<HepMC3::FourVector*>(v)->pz();
    }

    double fourvector_e(void* v) {
        return static_cast<HepMC3::FourVector*>(v)->e();
    }
}