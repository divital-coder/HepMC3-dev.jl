// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::Attribute> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::Attribute> : std::false_type { };
}

// Class generating the wrapper for type HepMC3::Attribute
// signature to use in the veto file: HepMC3::Attribute
struct JlHepMC3_Attribute: public Wrapper {

  JlHepMC3_Attribute(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::Attribute (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:44:7
    jlcxx::TypeWrapper<HepMC3::Attribute>  t = jlModule.add_type<HepMC3::Attribute>("HepMC3!Attribute");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::Attribute>>(new jlcxx::TypeWrapper<HepMC3::Attribute>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;

    DEBUG_MSG("Adding wrapper for bool HepMC3::Attribute::from_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::Attribute::from_string(const std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:77:18
    t.method("from_string", static_cast<bool (HepMC3::Attribute::*)(const std::string &) >(&HepMC3::Attribute::from_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::Attribute::init() (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::Attribute::init()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:81:18
    t.method("init", static_cast<bool (HepMC3::Attribute::*)() >(&HepMC3::Attribute::init));

    DEBUG_MSG("Adding wrapper for bool HepMC3::Attribute::init(const HepMC3::GenRunInfo &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::Attribute::init(const HepMC3::GenRunInfo &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:90:18
    t.method("init", static_cast<bool (HepMC3::Attribute::*)(const HepMC3::GenRunInfo &) >(&HepMC3::Attribute::init));

    DEBUG_MSG("Adding wrapper for bool HepMC3::Attribute::to_string(std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::Attribute::to_string(std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:95:18
    t.method("to_string", static_cast<bool (HepMC3::Attribute::*)(std::string &)  const>(&HepMC3::Attribute::to_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::Attribute::is_parsed() (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::Attribute::is_parsed()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:102:10
    t.method("is_parsed", static_cast<bool (HepMC3::Attribute::*)()  const>(&HepMC3::Attribute::is_parsed));

    DEBUG_MSG("Adding wrapper for const std::string & HepMC3::Attribute::unparsed_string() (" __HERE__ ")");
    // signature to use in the veto list: const std::string & HepMC3::Attribute::unparsed_string()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:105:24
    t.method("unparsed_string", static_cast<const std::string & (HepMC3::Attribute::*)()  const>(&HepMC3::Attribute::unparsed_string));

    DEBUG_MSG("Adding wrapper for const HepMC3::GenEvent * HepMC3::Attribute::event() (" __HERE__ ")");
    // signature to use in the veto list: const HepMC3::GenEvent * HepMC3::Attribute::event()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:108:22
    t.method("event", static_cast<const HepMC3::GenEvent * (HepMC3::Attribute::*)()  const>(&HepMC3::Attribute::event));

    DEBUG_MSG("Adding wrapper for HepMC3::GenParticlePtr HepMC3::Attribute::particle() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::GenParticlePtr HepMC3::Attribute::particle()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:113:20
    t.method("particle", static_cast<HepMC3::GenParticlePtr (HepMC3::Attribute::*)() >(&HepMC3::Attribute::particle));

    DEBUG_MSG("Adding wrapper for HepMC3::GenVertexPtr HepMC3::Attribute::vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::GenVertexPtr HepMC3::Attribute::vertex()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:123:18
    t.method("vertex", static_cast<HepMC3::GenVertexPtr (HepMC3::Attribute::*)() >(&HepMC3::Attribute::vertex));

    DEBUG_MSG("Adding wrapper for HepMC3::ConstGenVertexPtr HepMC3::Attribute::vertex() (" __HERE__ ")");
    // signature to use in the veto list: HepMC3::ConstGenVertexPtr HepMC3::Attribute::vertex()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:128:23
    t.method("vertex", static_cast<HepMC3::ConstGenVertexPtr (HepMC3::Attribute::*)()  const>(&HepMC3::Attribute::vertex));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::Attribute>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_Attribute(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_Attribute(module));
}
