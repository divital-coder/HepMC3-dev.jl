Julia bindings for the [HepMC3](https://gitlab.cern.ch/hepmc/HepMC3) library for
representing HEP monte-carlo events. The bindings use the
[CxxWrap.jl](https://github.com/JuliaInterop/CxxWrap.jl) package to wrap C++
types and functions to Julia. These are generated using the
[WrapIt](https://github.com/grasph/wrapit) package, which automates the
generation of the wrapper code by analysing the HepMC3 header files.


Instructions code for execution : 
```
git clone https://github.com/divital-coder/HepMC3-dev.jl.git
cd HepMC3-dev.jl
git checkout hepmc3_macos
rm ./wrapit
julia --project=. -e "using Pkg; Pkg.add(\"CxxWrap\"); Pkg.add(\"WrapIt\"); using WrapIt; WrapIt.install(); Pkg.instantiate();"
rm -rf gen/build/*
julia --project=. gen/build.jl
julia --project=. test/runtests.jl
```

