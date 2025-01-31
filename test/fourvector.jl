# Test the wrapped library for HepMC3 4-vectors
#

using Test

include(joinpath(@__DIR__, "load_module.jl"))

@testset "HepMC3 FourVector" begin
    v1 = HepMC3!FourVector()
    v2 = HepMC3!FourVector(1.2, 2.3, 3.4, 4.5)

    @test x(v2) == 1.2
    @test y(v2) == 2.3
    @test z(v2) == 3.4
    @test t(v2) == 4.5

    v3 = v1 + v2
    @test px(v3) == px(v2)
    @test py(v3) == py(v2)
    @test pz(v3) == pz(v2)
    @test e(v3) == e(v2)

    @test HepMC3.is_zero(v1)

    v4 = v3
    set_px(v4, 9.99)
    @test px(v4) == 9.99

    @test HepMC3.length(v4) ≈ 10.800467582470677
    @test HepMC3.phi(v4) ≈ 0.22628703995351376
    @test HepMC3.rap(v4) ≈ 0.9857762898343254
    @test HepMC3.eta(v4) ≈ 0.32586585368690585

    px!(v3, -9.99)
    @test px(v3) == -9.99
    e!(v3, 189.99)
    @test e(v3) == 189.99

end
