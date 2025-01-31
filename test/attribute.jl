# Test the wrapped library for HepMC3 attributes
#

using Test

include(joinpath(@__DIR__, "load_module.jl"))

@testset "HepMC3 Attribute" begin
    boolval = HepMC3!BoolAttribute()
    @test value(boolval) == false
    set_value(boolval, true)
    @test value(boolval) == true

    intval = HepMC3!IntAttribute()
    @test value(intval) == 0
    set_value(intval, 666)
    @test value(intval) == 666
    @test value!(intval, 678) === nothing
    @test value(intval) == 678
    my_str = ""
    @test to_string(intval, my_str) # The string does not change, passed by value somewhere?
    @test from_string(intval, "123") == true
    @test value(intval) == 123

    doubleval = HepMC3!DoubleAttribute()
    @test value(doubleval) == 0.0
    set_value(doubleval, -666.666)
    @test value(doubleval) == -666.666
    @test value!(doubleval, 678.99) === nothing
    @test value(doubleval) == 678.99
    @test to_string(doubleval, my_str) # The string does not change, passed by value somewhere?
    @test from_string(doubleval, "123.321") == true
    @test value(doubleval) == 123.321

end
