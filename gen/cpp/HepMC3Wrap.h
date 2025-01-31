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


    // Heavy Ion functions
    void* create_heavy_ion();
    void set_heavy_ion_basic(void* hi, int ncoll_hard, int npart_proj, int npart_targ, int ncoll,
                            int n_n_wounded, int nwounded_n, int nwounded_nwounded,
                            double impact_param, double event_plane_angle);
    void set_heavy_ion_nuclear(void* hi, int nspec_proj_n, int nspec_targ_n, 
                             int nspec_proj_p, int nspec_targ_p);
    void set_heavy_ion_centrality(void* hi, double sigma_inel_nn, double centrality, 
                                double user_cent_estimate);
    void set_heavy_ion_participant_plane_angle(void* hi, int order, double angle);
    void set_heavy_ion_eccentricity(void* hi, int order, double ecc);
    
    // Getters
    int get_ncoll_hard(void* hi);
    int get_npart_proj(void* hi);
    int get_npart_targ(void* hi);
    int get_ncoll(void* hi);
    int get_n_n_wounded(void* hi);
    int get_nwounded_n(void* hi);
    int get_nwounded_nwounded(void* hi);
    double get_impact_parameter(void* hi);
    double get_event_plane_angle(void* hi);
    int get_nspec_proj_n(void* hi);
    int get_nspec_targ_n(void* hi);
    int get_nspec_proj_p(void* hi);
    int get_nspec_targ_p(void* hi);
    double get_sigma_inel_nn(void* hi);
    double get_centrality(void* hi);
    double get_user_cent_estimate(void* hi);
    double get_participant_plane_angle(void* hi, int order);
    double get_eccentricity(void* hi, int order);
    void add_heavy_ion_to_event(void* event, void* hi);

    // Event traversal functions
    int event_particles_size(void* event);
    int event_vertices_size(void* event);
    void* event_particle_at(void* event, int index);
    void* event_vertex_at(void* event, int index);
    
    // Particle search and filtering
    void* create_particle_vector();
    void delete_particle_vector(void* vec);
    int particle_vector_size(void* vec);
    void* particle_vector_at(void* vec, int index);
    void find_particles_by_pid(void* event, void* result_vec, int pid);
    
    // Vertex traversal
    void* vertex_particles_in(void* vertex, void* result_vec);
    void* vertex_particles_out(void* vertex, void* result_vec);
    void* particle_production_vertex(void* particle);
    void* particle_end_vertex(void* particle);
    void* particle_parents(void* particle, void* result_vec);
    void* particle_children(void* particle, void* result_vec);
    
    // Event statistics
    int event_particles_with_status(void* event, int status);
    double event_total_momentum(void* event, int component); // 0=E, 1=px, 2=py, 3=pz
    bool event_is_valid(void* event);


    // Units conversion functions
    void convert_momentum(void* four_vector, int from_unit, int to_unit);
    void convert_length(void* four_vector, int from_unit, int to_unit);
    
    // Unit conversion for events
    void convert_event_units(void* event, int new_momentum_unit, int new_length_unit);
    
    // Unit getters for events
    int get_momentum_unit(void* event);
    int get_length_unit(void* event);
    
    // Unit name conversions
    const char* momentum_unit_name(int unit);
    const char* length_unit_name(int unit);

    void* create_genevent_with_units(int momentum_unit, int length_unit);


    // Attribute creation
    void* create_int_attribute(int value);
    void* create_double_attribute(double value);
    void* create_string_attribute(const char* value);
    void* create_bool_attribute(bool value);
    
    // Attribute handling
    void add_attribute_to_event(void* event, const char* name, void* attr);
    void* get_attribute_from_event(void* event, const char* name);
    bool has_attribute(void* event, const char* name);
    void remove_attribute(void* event, const char* name);
    
    // Attribute value getters
    int get_int_attribute_value(void* attr);
    double get_double_attribute_value(void* attr);
    const char* get_string_attribute_value(void* attr);
    bool get_bool_attribute_value(void* attr);
}

#endif