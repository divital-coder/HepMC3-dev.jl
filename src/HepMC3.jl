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