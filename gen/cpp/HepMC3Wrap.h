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

    // Vertex functions
    void* create_vertex();
    void add_particle_in(void* vertex, void* particle);
    void add_particle_out(void* vertex, void* particle);
    void set_vertex_status(void* vertex, int status);
    int vertex_status(void* vertex);
    void add_vertex_to_event(void* event, void* vertex);


      // GenCrossSection functions
    void* create_cross_section();
    void set_cross_section(void* xs, double value, double error);
    double get_cross_section(void* xs);
    double get_cross_section_error(void* xs);
    void add_cross_section_to_event(void* event, void* xs);
    void set_cross_section_alternative(void* xs, double value, double error, int id);
    double get_cross_section_alternative(void* xs, int id);
    double get_cross_section_error_alternative(void* xs, int id);

    
    // PDF Information functions
    void* create_pdf_info();
    void set_pdf_info(void* pdf, int parton_id1, int parton_id2, double x1, double x2,
                     double scale, double xf1, double xf2, int pdf_id1, int pdf_id2);
    int get_parton_id1(void* pdf);
    int get_parton_id2(void* pdf);
    double get_x1(void* pdf);
    double get_x2(void* pdf);
    double get_scale(void* pdf);
    double get_xf1(void* pdf);
    double get_xf2(void* pdf);
    int get_pdf_id1(void* pdf);
    int get_pdf_id2(void* pdf);
    void add_pdf_info_to_event(void* event, void* pdf);
}
#endif