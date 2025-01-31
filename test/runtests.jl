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

