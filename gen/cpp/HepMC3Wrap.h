#ifndef HEPMC3_WRAP_H
#define HEPMC3_WRAP_H

#include "HepMC3/FourVector.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"
#include "HepMC3/Data/GenParticleData.h"
#include "HepMC3/Attribute.h"
#include "HepMC3/GenHeavyIon.h"
#include "HepMC3/GenPdfInfo.h"
#include "HepMC3/GenCrossSection.h"

#include "jlcxx/jlcxx.hpp"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

// Helper functions for shared_ptr handling
template<typename T>
std::shared_ptr<T> make_shared_from_ref(T& obj) {
    return std::make_shared<T>(obj);
}

template<typename T>
T* get_pointer(const std::shared_ptr<T>& ptr) {
    return ptr.get();
}

// C-style interface declarations (note the extern "C")
extern "C" {
    // FourVector functions
    void* create_fourvector(double x, double y, double z, double t);
    double fourvector_px(void* v);
    double fourvector_py(void* v);
    double fourvector_pz(void* v);
    double fourvector_e(void* v);

    // GenEvent functions
    void* create_genevent(int units);

    // GenParticle functions
    void* create_particle(void* momentum, int pdg_id, int status);
    int particle_pid(void* particle);
    int particle_status(void* particle);
    void* particle_momentum(void* particle);
    void set_particle_status(void* particle, int status);
    void set_particle_momentum(void* particle, void* momentum);
}

#endif