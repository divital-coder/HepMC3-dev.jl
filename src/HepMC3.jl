module HepMC3
using CxxWrap
using HepMC3_jll
using Libdl

# First load the wrapper module
const gendir = normpath(joinpath(@__DIR__, "../gen"))
const libpath = joinpath(gendir, "build/lib", "libHepMC3Wrap.$(Libdl.dlext)")

if !isfile(libpath)
    error("Wrapper library not found. Please build the package first.")
end

# Load the wrapper module first
@wrapmodule(()->libpath)

# Initialize CxxWrap
function __init__()
    @initcxx
end

# Include the generated exports if they exist
if isfile(joinpath(gendir, "jl/src/HepMC3-export.jl"))
    include(joinpath(gendir, "jl/src/HepMC3-export.jl"))
end

include("HepMC3Utils.jl")

# Define the abstract type for our wrapper
abstract type AbstractHepMC3Type end

# Define concrete types
mutable struct FourVector <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

mutable struct GenEvent <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

mutable struct GenParticle <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

# Constructor functions
"""
    FourVector(x::Float64, y::Float64, z::Float64, t::Float64)
Create a new four-vector with components (x,y,z,t).
"""
function FourVector(x::Float64, y::Float64, z::Float64, t::Float64)
    ptr = ccall((:create_fourvector, libpath), Ptr{Cvoid}, 
                (Float64, Float64, Float64, Float64), x, y, z, t)
    FourVector(ptr)
end

"""
    GenEvent(units::Int = -1)
Create a new GenEvent with optional units specification.
"""
function GenEvent(units::Int = -1)
    ptr = ccall((:create_genevent, libpath), Ptr{Cvoid}, (Int32,), units)
    GenEvent(ptr)
end

"""
    GenParticle(momentum::FourVector, pdg_id::Int, status::Int)
Create a new particle with given momentum, PDG ID, and status code.
"""
function GenParticle(momentum::FourVector, pdg_id::Int, status::Int)
    ptr = ccall((:create_particle, libpath), Ptr{Cvoid},
                (Ptr{Cvoid}, Int32, Int32), momentum.ptr, pdg_id, status)
    GenParticle(ptr)
end

# Add accessor functions for FourVector
function px(v::FourVector)
    ccall((:fourvector_px, libpath), Float64, (Ptr{Cvoid},), v.ptr)
end

function py(v::FourVector)
    ccall((:fourvector_py, libpath), Float64, (Ptr{Cvoid},), v.ptr)
end

function pz(v::FourVector)
    ccall((:fourvector_pz, libpath), Float64, (Ptr{Cvoid},), v.ptr)
end

function e(v::FourVector)
    ccall((:fourvector_e, libpath), Float64, (Ptr{Cvoid},), v.ptr)
end

# Add accessor functions for GenParticle
"""
    pid(particle::GenParticle)
Get the PDG ID of a particle.
"""
function pid(particle::GenParticle)
    ccall((:particle_pid, libpath), Int32, (Ptr{Cvoid},), particle.ptr)
end

"""
    status(particle::GenParticle)
Get the status code of a particle.
"""
function status(particle::GenParticle)
    ccall((:particle_status, libpath), Int32, (Ptr{Cvoid},), particle.ptr)
end

"""
    momentum(particle::GenParticle)
Get the four-momentum of a particle.
"""
function momentum(particle::GenParticle)
    ptr = ccall((:particle_momentum, libpath), Ptr{Cvoid}, (Ptr{Cvoid},), particle.ptr)
    FourVector(ptr)
end

"""
    set_status!(particle::GenParticle, status::Int)
Set the status code of a particle.
"""
function set_status!(particle::GenParticle, status::Int)
    ccall((:set_particle_status, libpath), Cvoid,
          (Ptr{Cvoid}, Int32), particle.ptr, status)
end

"""
    set_momentum!(particle::GenParticle, momentum::FourVector)
Set the four-momentum of a particle.
"""
function set_momentum!(particle::GenParticle, momentum::FourVector)
    ccall((:set_particle_momentum, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), particle.ptr, momentum.ptr)
end



# Add new type
mutable struct GenVertex <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

# Add new functions
"""
    GenVertex()
Create a new vertex.
"""
function GenVertex()
    ptr = ccall((:create_vertex, libpath), Ptr{Cvoid}, ())
    GenVertex(ptr)
end

"""
    add_particle_in!(vertex::GenVertex, particle::GenParticle)
Add an incoming particle to the vertex.
"""
function add_particle_in!(vertex::GenVertex, particle::GenParticle)
    ccall((:add_particle_in, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), vertex.ptr, particle.ptr)
end

"""
    add_particle_out!(vertex::GenVertex, particle::GenParticle)
Add an outgoing particle to the vertex.
"""
function add_particle_out!(vertex::GenVertex, particle::GenParticle)
    ccall((:add_particle_out, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), vertex.ptr, particle.ptr)
end

"""
    vertex_status(vertex::GenVertex)
Get the status code of a vertex.
"""
function vertex_status(vertex::GenVertex)
    ccall((:vertex_status, libpath), Int32, (Ptr{Cvoid},), vertex.ptr)
end

"""
    set_vertex_status!(vertex::GenVertex, status::Int)
Set the status code of a vertex.
"""
function set_vertex_status!(vertex::GenVertex, status::Int)
    ccall((:set_vertex_status, libpath), Cvoid,
          (Ptr{Cvoid}, Int32), vertex.ptr, status)
end

"""
    add_vertex!(event::GenEvent, vertex::GenVertex)
Add a vertex to an event.
"""
function add_vertex!(event::GenEvent, vertex::GenVertex)
    ccall((:add_vertex_to_event, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), event.ptr, vertex.ptr)
end









# Add new type
mutable struct GenCrossSection <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

"""
    GenCrossSection()

Create a new cross-section object.
"""
function GenCrossSection()
    ptr = ccall((:create_cross_section, libpath), Ptr{Cvoid}, ())
    GenCrossSection(ptr)
end

"""
    set_cross_section!(xs::GenCrossSection, value::Float64, error::Float64)

Set the cross-section value and its error.
"""
function set_cross_section!(xs::GenCrossSection, value::Float64, error::Float64)
    ccall((:set_cross_section, libpath), Cvoid,
          (Ptr{Cvoid}, Float64, Float64), xs.ptr, value, error)
end

"""
    cross_section(xs::GenCrossSection)

Get the cross-section value.
"""
function cross_section(xs::GenCrossSection)
    ccall((:get_cross_section, libpath), Float64, (Ptr{Cvoid},), xs.ptr)
end

"""
    cross_section_error(xs::GenCrossSection)

Get the cross-section error.
"""
function cross_section_error(xs::GenCrossSection)
    ccall((:get_cross_section_error, libpath), Float64, (Ptr{Cvoid},), xs.ptr)
end

"""
    add_cross_section!(event::GenEvent, xs::GenCrossSection)

Add a cross-section to an event.
"""
function add_cross_section!(event::GenEvent, xs::GenCrossSection)
    ccall((:add_cross_section_to_event, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), event.ptr, xs.ptr)
end

"""
    set_alternative_cross_section!(xs::GenCrossSection, value::Float64, error::Float64, id::Int)

Set an alternative cross-section value with a specific ID.
Note: The error parameter is currently not used as HepMC3 doesn't support separate errors for alternative cross-sections.
"""
function set_alternative_cross_section!(xs::GenCrossSection, value::Float64, error::Float64, id::Int)
    ccall((:set_cross_section_alternative, libpath), Cvoid,
          (Ptr{Cvoid}, Float64, Float64, Int32), xs.ptr, value, error, id)
end

"""
    alternative_cross_section(xs::GenCrossSection, id::Int)

Get an alternative cross-section value by ID.
"""
function alternative_cross_section(xs::GenCrossSection, id::Int)
    ccall((:get_cross_section_alternative, libpath), Float64,
          (Ptr{Cvoid}, Int32), xs.ptr, id)
end

"""
    alternative_cross_section_error(xs::GenCrossSection, id::Int)
Get an alternative cross-section error by ID.
Note: This always returns 0.0 as HepMC3 doesn't support separate errors for alternative cross-sections.
"""
function alternative_cross_section_error(xs::GenCrossSection, id::Int)
    # ccall((:get_cross_section_error_alternative, libpath), Float64,
    #       (Ptr{Cvoid}, Int32), xs.ptr, id)
    @info "HepMC3 doesn't support separate errors for alternative cross-sections."
    return 0.0
end








# Add new type
mutable struct GenPdfInfo <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

"""
    GenPdfInfo()

Create a new PDF information object.
"""
function GenPdfInfo()
    ptr = ccall((:create_pdf_info, libpath), Ptr{Cvoid}, ())
    GenPdfInfo(ptr)
end

"""
    set_pdf_info!(pdf::GenPdfInfo, parton_id1::Int, parton_id2::Int, x1::Float64, x2::Float64,
                 scale::Float64, xf1::Float64, xf2::Float64, pdf_id1::Int, pdf_id2::Int)

Set all PDF information at once.
"""
function set_pdf_info!(pdf::GenPdfInfo, parton_id1::Int, parton_id2::Int, x1::Float64, x2::Float64,
                      scale::Float64, xf1::Float64, xf2::Float64, pdf_id1::Int, pdf_id2::Int)
    ccall((:set_pdf_info, libpath), Cvoid,
          (Ptr{Cvoid}, Int32, Int32, Float64, Float64, Float64, Float64, Float64, Int32, Int32),
          pdf.ptr, parton_id1, parton_id2, x1, x2, scale, xf1, xf2, pdf_id1, pdf_id2)
end

"""
    parton_id1(pdf::GenPdfInfo)

Get the PDG ID of the first parton.
"""
function parton_id1(pdf::GenPdfInfo)
    ccall((:get_parton_id1, libpath), Int32, (Ptr{Cvoid},), pdf.ptr)
end

"""
    parton_id2(pdf::GenPdfInfo)

Get the PDG ID of the second parton.
"""
function parton_id2(pdf::GenPdfInfo)
    ccall((:get_parton_id2, libpath), Int32, (Ptr{Cvoid},), pdf.ptr)
end

"""
    x1(pdf::GenPdfInfo)

Get the momentum fraction of the first parton.
"""
function x1(pdf::GenPdfInfo)
    ccall((:get_x1, libpath), Float64, (Ptr{Cvoid},), pdf.ptr)
end

"""
    x2(pdf::GenPdfInfo)

Get the momentum fraction of the second parton.
"""
function x2(pdf::GenPdfInfo)
    ccall((:get_x2, libpath), Float64, (Ptr{Cvoid},), pdf.ptr)
end

"""
    scale(pdf::GenPdfInfo)

Get the scale at which PDFs are evaluated.
"""
function scale(pdf::GenPdfInfo)
    ccall((:get_scale, libpath), Float64, (Ptr{Cvoid},), pdf.ptr)
end

"""
    xf1(pdf::GenPdfInfo)

Get the PDF value for the first parton.
"""
function xf1(pdf::GenPdfInfo)
    ccall((:get_xf1, libpath), Float64, (Ptr{Cvoid},), pdf.ptr)
end

"""
    xf2(pdf::GenPdfInfo)

Get the PDF value for the second parton.
"""
function xf2(pdf::GenPdfInfo)
    ccall((:get_xf2, libpath), Float64, (Ptr{Cvoid},), pdf.ptr)
end

"""
    pdf_id1(pdf::GenPdfInfo)

Get the PDF set ID for the first parton.
"""
function pdf_id1(pdf::GenPdfInfo)
    ccall((:get_pdf_id1, libpath), Int32, (Ptr{Cvoid},), pdf.ptr)
end

"""
    pdf_id2(pdf::GenPdfInfo)

Get the PDF set ID for the second parton.
"""
function pdf_id2(pdf::GenPdfInfo)
    ccall((:get_pdf_id2, libpath), Int32, (Ptr{Cvoid},), pdf.ptr)
end

"""
    add_pdf_info!(event::GenEvent, pdf::GenPdfInfo)

Add PDF information to an event.
"""
function add_pdf_info!(event::GenEvent, pdf::GenPdfInfo)
    ccall((:add_pdf_info_to_event, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), event.ptr, pdf.ptr)
end




# Add new type
mutable struct GenHeavyIon <: AbstractHepMC3Type
    ptr::Ptr{Cvoid}
end

"""
    GenHeavyIon()

Create a new Heavy Ion information object.
"""
function GenHeavyIon()
    ptr = ccall((:create_heavy_ion, libpath), Ptr{Cvoid}, ())
    GenHeavyIon(ptr)
end

"""
    set_heavy_ion_basic!(hi::GenHeavyIon, ncoll_hard::Int, npart_proj::Int, npart_targ::Int, 
                        ncoll::Int, n_n_wounded::Int, nwounded_n::Int, nwounded_nwounded::Int,
                        impact_param::Float64, event_plane_angle::Float64)

Set basic heavy ion collision properties.
"""
function set_heavy_ion_basic!(hi::GenHeavyIon, ncoll_hard::Int, npart_proj::Int, npart_targ::Int, 
                            ncoll::Int, n_n_wounded::Int, nwounded_n::Int, nwounded_nwounded::Int,
                            impact_param::Float64, event_plane_angle::Float64)
    ccall((:set_heavy_ion_basic, libpath), Cvoid,
          (Ptr{Cvoid}, Int32, Int32, Int32, Int32, Int32, Int32, Int32, Float64, Float64),
          hi.ptr, ncoll_hard, npart_proj, npart_targ, ncoll, n_n_wounded, nwounded_n, 
          nwounded_nwounded, impact_param, event_plane_angle)
end

"""
    set_heavy_ion_nuclear!(hi::GenHeavyIon, nspec_proj_n::Int, nspec_targ_n::Int, 
                          nspec_proj_p::Int, nspec_targ_p::Int)

Set nuclear properties for heavy ion collision.
"""
function set_heavy_ion_nuclear!(hi::GenHeavyIon, nspec_proj_n::Int, nspec_targ_n::Int, 
                              nspec_proj_p::Int, nspec_targ_p::Int)
    ccall((:set_heavy_ion_nuclear, libpath), Cvoid,
          (Ptr{Cvoid}, Int32, Int32, Int32, Int32),
          hi.ptr, nspec_proj_n, nspec_targ_n, nspec_proj_p, nspec_targ_p)
end

"""
    set_heavy_ion_centrality!(hi::GenHeavyIon, sigma_inel_nn::Float64, centrality::Float64, 
                            user_cent_estimate::Float64)

Set centrality-related properties for heavy ion collision.
"""
function set_heavy_ion_centrality!(hi::GenHeavyIon, sigma_inel_nn::Float64, centrality::Float64, 
                                 user_cent_estimate::Float64)
    ccall((:set_heavy_ion_centrality, libpath), Cvoid,
          (Ptr{Cvoid}, Float64, Float64, Float64),
          hi.ptr, sigma_inel_nn, centrality, user_cent_estimate)
end

"""
    set_participant_plane_angle!(hi::GenHeavyIon, order::Int, angle::Float64)

Set participant plane angle for a specific order.
"""
function set_participant_plane_angle!(hi::GenHeavyIon, order::Int, angle::Float64)
    ccall((:set_heavy_ion_participant_plane_angle, libpath), Cvoid,
          (Ptr{Cvoid}, Int32, Float64),
          hi.ptr, order, angle)
end

"""
    set_eccentricity!(hi::GenHeavyIon, order::Int, ecc::Float64)

Set eccentricity for a specific order.
"""
function set_eccentricity!(hi::GenHeavyIon, order::Int, ecc::Float64)
    ccall((:set_heavy_ion_eccentricity, libpath), Cvoid,
          (Ptr{Cvoid}, Int32, Float64),
          hi.ptr, order, ecc)
end

# Getter functions
ncoll_hard(hi::GenHeavyIon) = ccall((:get_ncoll_hard, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
npart_proj(hi::GenHeavyIon) = ccall((:get_npart_proj, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
npart_targ(hi::GenHeavyIon) = ccall((:get_npart_targ, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
ncoll(hi::GenHeavyIon) = ccall((:get_ncoll, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
n_n_wounded(hi::GenHeavyIon) = ccall((:get_n_n_wounded, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
nwounded_n(hi::GenHeavyIon) = ccall((:get_nwounded_n, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
nwounded_nwounded(hi::GenHeavyIon) = ccall((:get_nwounded_nwounded, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
impact_parameter(hi::GenHeavyIon) = ccall((:get_impact_parameter, libpath), Float64, (Ptr{Cvoid},), hi.ptr)
event_plane_angle(hi::GenHeavyIon) = ccall((:get_event_plane_angle, libpath), Float64, (Ptr{Cvoid},), hi.ptr)
nspec_proj_n(hi::GenHeavyIon) = ccall((:get_nspec_proj_n, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
nspec_targ_n(hi::GenHeavyIon) = ccall((:get_nspec_targ_n, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
nspec_proj_p(hi::GenHeavyIon) = ccall((:get_nspec_proj_p, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
nspec_targ_p(hi::GenHeavyIon) = ccall((:get_nspec_targ_p, libpath), Int32, (Ptr{Cvoid},), hi.ptr)
sigma_inel_nn(hi::GenHeavyIon) = ccall((:get_sigma_inel_nn, libpath), Float64, (Ptr{Cvoid},), hi.ptr)
centrality(hi::GenHeavyIon) = ccall((:get_centrality, libpath), Float64, (Ptr{Cvoid},), hi.ptr)
user_cent_estimate(hi::GenHeavyIon) = ccall((:get_user_cent_estimate, libpath), Float64, (Ptr{Cvoid},), hi.ptr)

function participant_plane_angle(hi::GenHeavyIon, order::Int)
    ccall((:get_participant_plane_angle, libpath), Float64, (Ptr{Cvoid}, Int32), hi.ptr, order)
end

function eccentricity(hi::GenHeavyIon, order::Int)
    ccall((:get_eccentricity, libpath), Float64, (Ptr{Cvoid}, Int32), hi.ptr, order)
end

"""
    add_heavy_ion!(event::GenEvent, hi::GenHeavyIon)

Add heavy ion information to an event.
"""
function add_heavy_ion!(event::GenEvent, hi::GenHeavyIon)
    ccall((:add_heavy_ion_to_event, libpath), Cvoid,
          (Ptr{Cvoid}, Ptr{Cvoid}), event.ptr, hi.ptr)
end

# Add to your exports
export GenHeavyIon
export set_heavy_ion_basic!, set_heavy_ion_nuclear!, set_heavy_ion_centrality!
export set_participant_plane_angle!, set_eccentricity!
export ncoll_hard, npart_proj, npart_targ, ncoll
export n_n_wounded, nwounded_n, nwounded_nwounded
export impact_parameter, event_plane_angle
export nspec_proj_n, nspec_targ_n, nspec_proj_p, nspec_targ_p
export sigma_inel_nn, centrality, user_cent_estimate
export participant_plane_angle, eccentricity
export add_heavy_ion!



















# Add exports
export GenPdfInfo
export set_pdf_info!
export parton_id1, parton_id2
export x1, x2, scale
export xf1, xf2
export pdf_id1, pdf_id2
export add_pdf_info!


# Add exports
export GenCrossSection
export set_cross_section!, cross_section, cross_section_error
export add_cross_section!
export set_alternative_cross_section!, alternative_cross_section, alternative_cross_section_error


# Add exports
export GenVertex
export add_particle_in!, add_particle_out!
export vertex_status, set_vertex_status!
export add_vertex!


# Export the interface
export FourVector, GenEvent, GenVertex, GenParticle
export px, py, pz, e
export pid, status, momentum, set_status!, set_momentum!

end # module