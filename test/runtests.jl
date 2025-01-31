# test/runtests.jl
using HepMC3
using Test

@testset "HepMC3.jl" begin
    @testset "FourVector" begin
        # Basic construction and accessors
        v = FourVector(1.0, 2.0, 3.0, 4.0)
        @test px(v) ≈ 1.0
        @test py(v) ≈ 2.0
        @test pz(v) ≈ 3.0
        @test e(v) ≈ 4.0

        # Test with different values
        v2 = FourVector(5.0, 6.0, 7.0, 8.0)
        @test px(v2) ≈ 5.0
        @test py(v2) ≈ 6.0
        @test pz(v2) ≈ 7.0
        @test e(v2) ≈ 8.0
    end

    @testset "GenEvent" begin
        # Basic event creation
        evt = GenEvent()
        @test !isnothing(evt)

        # Test with specific units
        evt_gev = GenEvent(1)  # GEV
        @test !isnothing(evt_gev)
    end
end

@testset "HepMC3.jl" begin
    @testset "FourVector" begin
        # Create a simple four-vector
        v = FourVector(1.0, 2.0, 3.0, 4.0)
        
        # Test basic accessors
        @test px(v) ≈ 1.0
        @test py(v) ≈ 2.0
        @test pz(v) ≈ 3.0
        @test e(v) ≈ 4.0
    end

    @testset "GenEvent" begin
        # Create a simple event
        evt = GenEvent()
        @test !isnothing(evt)
    end
end

@testset "HepMC3.jl" begin
    # ... existing tests ...

    @testset "GenParticle" begin
        # Create a particle
        mom = FourVector(1.0, 2.0, 3.0, 4.0)
        p = GenParticle(mom, 11, 1)  # electron with status 1
        
        # Test basic properties
        @test pid(p) == 11
        @test status(p) == 1
        
        # Test momentum
        pmom = momentum(p)
        @test px(pmom) ≈ 1.0
        @test py(pmom) ≈ 2.0
        @test pz(pmom) ≈ 3.0
        @test e(pmom) ≈ 4.0
        
        # Test setters
        set_status!(p, 2)
        @test status(p) == 2
        
        new_mom = FourVector(5.0, 6.0, 7.0, 8.0)
        set_momentum!(p, new_mom)
        updated_mom = momentum(p)
        @test px(updated_mom) ≈ 5.0
        @test py(updated_mom) ≈ 6.0
        @test pz(updated_mom) ≈ 7.0
        @test e(updated_mom) ≈ 8.0
    end
end

