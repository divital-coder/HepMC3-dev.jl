# Extra methods for HepMC3 that provide a better user interface than
# the wrapped C++ calls

# FourVector pretty print
Base.show(io::IO, v::HepMC3!FourVector) = print(io, "($(px(v)), $(py(v)), $(pz(v)), $(e(v)))")
Base.show(io::IO, v::CxxWrap.CxxWrapCore.ConstCxxRef{HepMC3!FourVector}) = print(io, "($(px(v)), $(py(v)), $(pz(v)), $(e(v)))")

# Julian setters
const px!(v::HepMC3!FourVector, val) = set_px(v, val)
const py!(v::HepMC3!FourVector, val) = set_py(v, val)
const pz!(v::HepMC3!FourVector, val) = set_pz(v, val)
const e!(v::HepMC3!FourVector, val) = set_e(v, val)
export px!, py!, pz!, e!

# Attribute pretty print
Base.show(io::IO, a::Main.HepMC3.HepMC3!Attribute) = print(io, value(a))

# More Julian way to update the value of the attribute
const value!(a::Main.HepMC3.HepMC3!Attribute, v) = set_value(a, v)
export value!
