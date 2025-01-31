module HepMC3


using CxxWrap
import Libdl
@wrapmodule(()->"$(@__DIR__)/../deps/libjlHepMC3." * Libdl.dlext)

function __init__()
    @initcxx
end

end #module
