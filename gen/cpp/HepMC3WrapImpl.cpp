#include "HepMC3Wrap.h"

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
        return new HepMC3::GenParticle(*mom, pdg_id, status);
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

    int particle_pid(void* particle) {
        return static_cast<HepMC3::GenParticle*>(particle)->pid();
    }

    int particle_status(void* particle) {
        return static_cast<HepMC3::GenParticle*>(particle)->status();
    }

    void* particle_momentum(void* particle) {
        return new HepMC3::FourVector(static_cast<HepMC3::GenParticle*>(particle)->momentum());
    }

    void set_particle_status(void* particle, int status) {
        static_cast<HepMC3::GenParticle*>(particle)->set_status(status);
    }

    void set_particle_momentum(void* particle, void* momentum) {
        auto* mom = static_cast<HepMC3::FourVector*>(momentum);
        static_cast<HepMC3::GenParticle*>(particle)->set_momentum(*mom);
    }
}