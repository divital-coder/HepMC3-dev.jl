# Load the HepMC3 wrapped library

# Use an inline definition of the module, avoid the need for environment setup stuff
module HepMC3

using CxxWrap
using Libdl

wrapped_lib_path = joinpath(@__DIR__, "..", "gen", "build", "lib")

include(joinpath(@__DIR__, "..", "gen", "jl", "HepMC3-export.jl"))

@wrapmodule(()->joinpath(wrapped_lib_path, "libHepMC3Wrap.$(Libdl.dlext)"))

include(joinpath(@__DIR__, "..", "gen", "jl", "HepMC3-extras.jl"))

function __init__()
    @initcxx
end

end

# Import the library
using .HepMC3
