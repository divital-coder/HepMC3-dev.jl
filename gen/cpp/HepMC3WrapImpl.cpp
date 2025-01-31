#include "HepMC3Wrap.h"
#include <memory>
#include <unordered_map>
#include <string>

// Global storage for shared pointers to maintain ownership
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenParticle>> particle_store;
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenVertex>> vertex_store;
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenCrossSection>> xs_store;
static std::unordered_map<void*, std::shared_ptr<HepMC3::GenPdfInfo>> pdf_store;

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




    void* create_cross_section() {
        auto xs = std::make_shared<HepMC3::GenCrossSection>();
        void* ptr = xs.get();
        xs_store[ptr] = xs;
        return ptr;
    }

    void set_cross_section(void* xs, double value, double error) {
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            xs_it->second->set_cross_section(value, error);
        }
    }

    double get_cross_section(void* xs) {
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            return xs_it->second->xsec();
        }
        return 0.0;
    }

    double get_cross_section_error(void* xs) {
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            return xs_it->second->xsec_err();
        }
        return 0.0;
    }

    void add_cross_section_to_event(void* event, void* xs) {
        auto* evt = static_cast<HepMC3::GenEvent*>(event);
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            evt->set_cross_section(xs_it->second);
        }
    }

    void set_cross_section_alternative(void* xs, double value, double error, int id) {
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            // Convert id to string for named cross section
            std::string name = "alternative_" + std::to_string(id);
            xs_it->second->set_xsec(name, value);
            // Set the error separately if needed
            // Note: HepMC3 doesn't directly support setting errors for alternative cross sections
        }
    }

    double get_cross_section_alternative(void* xs, int id) {
        auto xs_it = xs_store.find(xs);
        if (xs_it != xs_store.end()) {
            std::string name = "alternative_" + std::to_string(id);
            return xs_it->second->xsec(name);
        }
        return 0.0;
    }

    double get_cross_section_error_alternative(void* xs, int id) {
        // Note: HepMC3 doesn't directly support getting errors for alternative cross sections
        // We'll return 0.0 as a default
        return 0.0;
    }

    void* create_pdf_info() {
        auto pdf = std::make_shared<HepMC3::GenPdfInfo>();
        void* ptr = pdf.get();
        pdf_store[ptr] = pdf;
        return ptr;
    }

    void set_pdf_info(void* pdf, int parton_id1, int parton_id2, double x1, double x2,
                     double scale, double xf1, double xf2, int pdf_id1, int pdf_id2) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            pdf_it->second->set(parton_id1, parton_id2, x1, x2, scale, xf1, xf2, pdf_id1, pdf_id2);
        }
    }

    int get_parton_id1(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->parton_id[0];  // Access first element of array
        }
        return 0;
    }

    int get_parton_id2(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->parton_id[1];  // Access second element of array
        }
        return 0;
    }

    double get_x1(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->x[0];  // Access first element of array
        }
        return 0.0;
    }

    double get_x2(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->x[1];  // Access second element of array
        }
        return 0.0;
    }

    double get_scale(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->scale;  // Direct member access
        }
        return 0.0;
    }

    double get_xf1(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->xf[0];  // Access first element of array
        }
        return 0.0;
    }

    double get_xf2(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->xf[1];  // Access second element of array
        }
        return 0.0;
    }

    int get_pdf_id1(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->pdf_id[0];  // Access first element of array
        }
        return 0;
    }

    int get_pdf_id2(void* pdf) {
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            return pdf_it->second->pdf_id[1];  // Access second element of array
        }
        return 0;
    }

    void add_pdf_info_to_event(void* event, void* pdf) {
        auto* evt = static_cast<HepMC3::GenEvent*>(event);
        auto pdf_it = pdf_store.find(pdf);
        if (pdf_it != pdf_store.end()) {
            evt->set_pdf_info(pdf_it->second);
        }
    }
}