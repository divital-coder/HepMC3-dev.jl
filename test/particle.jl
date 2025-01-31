# Test the wrapped library for HepMC3 particles
#

using Test

include(joinpath(@__DIR__, "load_module.jl"))

@testset "HepMC3 Particle" begin
    my_particle = HepMC3!GenParticle()
    @test pid(my_particle) == 0
    @test pdg_id(my_particle) == 0
    @test set_pid(my_particle, 11) === nothing
    @test set_pdg_id(my_particle, 11) === nothing
    @test pid(my_particle) == 11
    @test pdg_id(my_particle) == 11

    m = HepMC3!FourVector(2.3, 4.5, -9.4, 123.5)
    mp2 = HepMC3!GenParticle(m, 11, 1)
    @test pid(mp2) == 11
    @test status(mp2) == 1
    @test e(momentum(mp2)) == 123.5

end
