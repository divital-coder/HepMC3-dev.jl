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


@testset "Vertex and Event Construction" begin
    # Create particles
    p1 = GenParticle(FourVector(0.0, 0.0, 10.0, 10.0), 11, 1)   # incoming electron
    p2 = GenParticle(FourVector(0.0, 0.0, -10.0, 10.0), -11, 1) # incoming positron
    p3 = GenParticle(FourVector(10.0, 0.0, 0.0, 10.0), 22, 1)   # outgoing photon
    p4 = GenParticle(FourVector(-10.0, 0.0, 0.0, 10.0), 22, 1)  # outgoing photon

    # Create vertex
    v = GenVertex()
    @test !isnothing(v)

    # Add particles to vertex
    add_particle_in!(v, p1)
    add_particle_in!(v, p2)
    add_particle_out!(v, p3)
    add_particle_out!(v, p4)

    # Set and test vertex status
    set_vertex_status!(v, 1)
    @test vertex_status(v) == 1

    # Create event and add vertex
    evt = GenEvent()
    add_vertex!(evt, v)
    @test !isnothing(evt)
end


@testset "Cross Section" begin
    # Create a cross-section object
    xs = GenCrossSection()
    @test !isnothing(xs)

    # Test basic cross-section
    set_cross_section!(xs, 100.0, 10.0)
    @test isapprox(cross_section(xs), 100.0, atol=1e-10)
    @test isapprox(cross_section_error(xs), 10.0, atol=1e-10)

    # Test alternative cross-sections
    set_alternative_cross_section!(xs, 200.0, 20.0, 1)
    @test isapprox(alternative_cross_section(xs, 1), 200.0, atol=1e-10)
    
    # Test adding cross-section to event
    evt = GenEvent()
    add_cross_section!(evt, xs)
    @test !isnothing(evt)
end



@testset "PDF Information" begin
    # Create a PDF info object
    pdf = GenPdfInfo()
    @test !isnothing(pdf)

    # Test setting and getting PDF information
    set_pdf_info!(pdf, 2, 1, 0.5, 0.3, 100.0, 0.7, 0.4, 1, 1)
    
    # Test parton IDs (up and down quarks)
    @test parton_id1(pdf) == 2  # up quark
    @test parton_id2(pdf) == 1  # down quark
    
    # Test momentum fractions
    @test isapprox(x1(pdf), 0.5, atol=1e-10)
    @test isapprox(x2(pdf), 0.3, atol=1e-10)
    
    # Test scale
    @test isapprox(scale(pdf), 100.0, atol=1e-10)
    
    # Test PDF values
    @test isapprox(xf1(pdf), 0.7, atol=1e-10)
    @test isapprox(xf2(pdf), 0.4, atol=1e-10)
    
    # Test PDF set IDs
    @test pdf_id1(pdf) == 1
    @test pdf_id2(pdf) == 1
    
    # Test adding PDF info to event
    evt = GenEvent()
    add_pdf_info!(evt, pdf)
    @test !isnothing(evt)
end

@testset "Heavy Ion" begin
    # Create a heavy ion object
    hi = GenHeavyIon()
    @test !isnothing(hi)

    # Test basic properties
    set_heavy_ion_basic!(hi, 100, 200, 200, 150, 50, 50, 50, 2.5, 0.5)
    @test ncoll_hard(hi) == 100
    @test npart_proj(hi) == 200
    @test npart_targ(hi) == 200
    @test ncoll(hi) == 150
    @test n_n_wounded(hi) == 50
    @test nwounded_n(hi) == 50
    @test nwounded_nwounded(hi) == 50
    @test impact_parameter(hi) ≈ 2.5
    @test event_plane_angle(hi) ≈ 0.5

    # Test nuclear properties
    set_heavy_ion_nuclear!(hi, 20, 20, 30, 30)
    @test nspec_proj_n(hi) == 20
    @test nspec_targ_n(hi) == 20
    @test nspec_proj_p(hi) == 30
    @test nspec_targ_p(hi) == 30

    # Test centrality properties
    set_heavy_ion_centrality!(hi, 42.0, 0.1, 0.15)
    @test sigma_inel_nn(hi) ≈ 42.0
    @test centrality(hi) ≈ 0.1
    @test user_cent_estimate(hi) ≈ 0.15

    # Test participant plane angles and eccentricities
    set_participant_plane_angle!(hi, 2, 0.3)
    set_participant_plane_angle!(hi, 3, 0.4)
    @test participant_plane_angle(hi, 2) ≈ 0.3
    @test participant_plane_angle(hi, 3) ≈ 0.4

    set_eccentricity!(hi, 2, 0.1)
    set_eccentricity!(hi, 3, 0.2)
    @test eccentricity(hi, 2) ≈ 0.1
    @test eccentricity(hi, 3) ≈ 0.2

    # Test adding to event
    evt = GenEvent()
    add_heavy_ion!(evt, hi)
    @test !isnothing(evt)
end