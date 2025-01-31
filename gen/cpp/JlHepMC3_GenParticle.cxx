// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::GenParticle> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::GenParticle> : std::false_type { };
}

// Class generating the wrapper for type HepMC3::GenParticle
// signature to use in the veto file: HepMC3::GenParticle
struct JlHepMC3_GenParticle: public Wrapper {

  JlHepMC3_GenParticle(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::GenParticle (" __HERE__ ")");
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:34:7
    jlcxx::TypeWrapper<HepMC3::GenParticle>  t = jlModule.add_type<HepMC3::GenParticle>("HepMC3!GenParticle");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::GenParticle>>(new jlcxx::TypeWrapper<HepMC3::GenParticle>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::GenParticle(const HepMC3::FourVector &, int, int) (" __HERE__ ")");
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:45:5
    t.constructor<const HepMC3::FourVector &>(/*finalize=*/jlcxx::finalize_policy::yes);
    t.constructor<const HepMC3::FourVector &, int>(/*finalize=*/jlcxx::finalize_policy::yes);
    t.constructor<const HepMC3::FourVector &, int, int>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::GenParticle(const HepMC3::GenParticleData &) (" __HERE__ ")");
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:48:5
    t.constructor<const HepMC3::GenParticleData &>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool HepMC3::GenParticle::in_event() (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::GenParticle::in_event()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:60:10
    t.method("in_event", static_cast<bool (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::in_event));

    DEBUG_MSG("Adding wrapper for HepMC3::GenEvent * HepMC3::GenParticle::parent_event() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::GenEvent * HepMC3::GenParticle::parent_event()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:63:15
    t.method("parent_event", static_cast<HepMC3::GenEvent * (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::parent_event));

    DEBUG_MSG("Adding wrapper for const HepMC3::GenEvent * HepMC3::GenParticle::parent_event() (" __HERE__ ")");
    // signature to use in the veto list: const HepMC3::GenEvent * HepMC3::GenParticle::parent_event()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:65:21
    t.method("parent_event", static_cast<const HepMC3::GenEvent * (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::parent_event));

    DEBUG_MSG("Adding wrapper for int HepMC3::GenParticle::id() (" __HERE__ ")");
    // signature to use in the veto list: int HepMC3::GenParticle::id()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:68:9
    t.method("id", static_cast<int (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::id));

    DEBUG_MSG("Adding wrapper for const HepMC3::GenParticleData & HepMC3::GenParticle::data() (" __HERE__ ")");
    // signature to use in the veto list: const HepMC3::GenParticleData & HepMC3::GenParticle::data()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:70:28
    t.method("data", static_cast<const HepMC3::GenParticleData & (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::data));

    DEBUG_MSG("Adding wrapper for HepMC3::ConstGenVertexPtr HepMC3::GenParticle::production_vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::ConstGenVertexPtr HepMC3::GenParticle::production_vertex()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:72:23
    t.method("production_vertex", static_cast<HepMC3::ConstGenVertexPtr (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::production_vertex));

    DEBUG_MSG("Adding wrapper for HepMC3::ConstGenVertexPtr HepMC3::GenParticle::end_vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::ConstGenVertexPtr HepMC3::GenParticle::end_vertex()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:73:23
    t.method("end_vertex", static_cast<HepMC3::ConstGenVertexPtr (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::end_vertex));

    DEBUG_MSG("Adding wrapper for HepMC3::GenVertexPtr HepMC3::GenParticle::production_vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::GenVertexPtr HepMC3::GenParticle::production_vertex()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:75:18
    t.method("production_vertex", static_cast<HepMC3::GenVertexPtr (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::production_vertex));

    DEBUG_MSG("Adding wrapper for HepMC3::GenVertexPtr HepMC3::GenParticle::end_vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::GenVertexPtr HepMC3::GenParticle::end_vertex()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:76:18
    t.method("end_vertex", static_cast<HepMC3::GenVertexPtr (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::end_vertex));

    DEBUG_MSG("Adding wrapper for std::vector<HepMC3::GenParticlePtr> HepMC3::GenParticle::parents() (" __HERE__ ")");
    // signature to use in the veto list: std::vector<HepMC3::GenParticlePtr> HepMC3::GenParticle::parents()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:80:33
    t.method("parents", static_cast<std::vector<HepMC3::GenParticlePtr> (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::parents));

    DEBUG_MSG("Adding wrapper for std::vector<HepMC3::GenParticlePtr> HepMC3::GenParticle::children() (" __HERE__ ")");
    // signature to use in the veto list: std::vector<HepMC3::GenParticlePtr> HepMC3::GenParticle::children()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:88:33
    t.method("children", static_cast<std::vector<HepMC3::GenParticlePtr> (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::children));

    DEBUG_MSG("Adding wrapper for int HepMC3::GenParticle::pid() (" __HERE__ ")");
    // signature to use in the veto list: int HepMC3::GenParticle::pid()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:94:11
    t.method("pid", static_cast<int (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::pid));

    DEBUG_MSG("Adding wrapper for int HepMC3::GenParticle::abs_pid() (" __HERE__ ")");
    // signature to use in the veto list: int HepMC3::GenParticle::abs_pid()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:95:11
    t.method("abs_pid", static_cast<int (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::abs_pid));

    DEBUG_MSG("Adding wrapper for int HepMC3::GenParticle::status() (" __HERE__ ")");
    // signature to use in the veto list: int HepMC3::GenParticle::status()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:96:11
    t.method("status", static_cast<int (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::status));

    DEBUG_MSG("Adding wrapper for const HepMC3::FourVector & HepMC3::GenParticle::momentum() (" __HERE__ ")");
    // signature to use in the veto list: const HepMC3::FourVector & HepMC3::GenParticle::momentum()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:97:23
    t.method("momentum", static_cast<const HepMC3::FourVector & (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::momentum));

    DEBUG_MSG("Adding wrapper for bool HepMC3::GenParticle::is_generated_mass_set() (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::GenParticle::is_generated_mass_set()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:98:11
    t.method("is_generated_mass_set", static_cast<bool (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::is_generated_mass_set));

    DEBUG_MSG("Adding wrapper for double HepMC3::GenParticle::generated_mass() (" __HERE__ ")");
    // signature to use in the veto list: double HepMC3::GenParticle::generated_mass()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:104:12
    t.method("generated_mass", static_cast<double (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::generated_mass));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::set_pid(int) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::set_pid(int)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:107:10
    t.method("set_pid", static_cast<void (HepMC3::GenParticle::*)(int) >(&HepMC3::GenParticle::set_pid));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::set_status(int) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::set_status(int)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:108:10
    t.method("set_status", static_cast<void (HepMC3::GenParticle::*)(int) >(&HepMC3::GenParticle::set_status));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::set_momentum(const HepMC3::FourVector &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::set_momentum(const HepMC3::FourVector &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:109:10
    t.method("set_momentum", static_cast<void (HepMC3::GenParticle::*)(const HepMC3::FourVector &) >(&HepMC3::GenParticle::set_momentum));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::set_generated_mass(double) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::set_generated_mass(double)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:110:10
    t.method("set_generated_mass", static_cast<void (HepMC3::GenParticle::*)(double) >(&HepMC3::GenParticle::set_generated_mass));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::unset_generated_mass() (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::unset_generated_mass()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:111:10
    t.method("unset_generated_mass", static_cast<void (HepMC3::GenParticle::*)() >(&HepMC3::GenParticle::unset_generated_mass));

    DEBUG_MSG("Adding wrapper for bool HepMC3::GenParticle::add_attribute(const std::string &, std::shared_ptr<HepMC3::Attribute>) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::GenParticle::add_attribute(const std::string &, std::shared_ptr<HepMC3::Attribute>)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:118:10
    t.method("add_attribute", static_cast<bool (HepMC3::GenParticle::*)(const std::string &, std::shared_ptr<HepMC3::Attribute>) >(&HepMC3::GenParticle::add_attribute));

    DEBUG_MSG("Adding wrapper for std::vector<std::string> HepMC3::GenParticle::attribute_names() (" __HERE__ ")");
    // signature to use in the veto list: std::vector<std::string> HepMC3::GenParticle::attribute_names()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:121:30
    t.method("attribute_names", static_cast<std::vector<std::string> (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::attribute_names));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::remove_attribute(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::remove_attribute(const std::string &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:124:10
    t.method("remove_attribute", static_cast<void (HepMC3::GenParticle::*)(const std::string &) >(&HepMC3::GenParticle::remove_attribute));

    DEBUG_MSG("Adding wrapper for std::string HepMC3::GenParticle::attribute_as_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: std::string HepMC3::GenParticle::attribute_as_string(const std::string &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:131:17
    t.method("attribute_as_string", static_cast<std::string (HepMC3::GenParticle::*)(const std::string &)  const>(&HepMC3::GenParticle::attribute_as_string));

    DEBUG_MSG("Adding wrapper for int HepMC3::GenParticle::pdg_id() (" __HERE__ ")");
    // signature to use in the veto list: int HepMC3::GenParticle::pdg_id()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:139:9
    t.method("pdg_id", static_cast<int (HepMC3::GenParticle::*)()  const>(&HepMC3::GenParticle::pdg_id));

    DEBUG_MSG("Adding wrapper for void HepMC3::GenParticle::set_pdg_id(const int &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::GenParticle::set_pdg_id(const int &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/GenParticle.h:143:10
    t.method("set_pdg_id", static_cast<void (HepMC3::GenParticle::*)(const int &) >(&HepMC3::GenParticle::set_pdg_id));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::GenParticle>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_GenParticle(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_GenParticle(module));
}
