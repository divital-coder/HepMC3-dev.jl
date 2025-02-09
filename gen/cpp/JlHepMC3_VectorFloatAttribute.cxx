// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::VectorFloatAttribute> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::VectorFloatAttribute> : std::false_type { };
template<> struct SuperType<HepMC3::VectorFloatAttribute> { typedef HepMC3::Attribute type; };
}

// Class generating the wrapper for type HepMC3::VectorFloatAttribute
// signature to use in the veto file: HepMC3::VectorFloatAttribute
struct JlHepMC3_VectorFloatAttribute: public Wrapper {

  JlHepMC3_VectorFloatAttribute(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::VectorFloatAttribute (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:753:7
    jlcxx::TypeWrapper<HepMC3::VectorFloatAttribute>  t = jlModule.add_type<HepMC3::VectorFloatAttribute>("HepMC3!VectorFloatAttribute",
      jlcxx::julia_base_type<HepMC3::Attribute>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::VectorFloatAttribute>>(new jlcxx::TypeWrapper<HepMC3::VectorFloatAttribute>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::VectorFloatAttribute::VectorFloatAttribute(std::vector<float>) (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:760:5
    t.constructor<std::vector<float>>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool HepMC3::VectorFloatAttribute::from_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::VectorFloatAttribute::from_string(const std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:763:10
    t.method("from_string", static_cast<bool (HepMC3::VectorFloatAttribute::*)(const std::string &) >(&HepMC3::VectorFloatAttribute::from_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::VectorFloatAttribute::to_string(std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::VectorFloatAttribute::to_string(std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:773:10
    t.method("to_string", static_cast<bool (HepMC3::VectorFloatAttribute::*)(std::string &)  const>(&HepMC3::VectorFloatAttribute::to_string));

    DEBUG_MSG("Adding wrapper for std::vector<float> HepMC3::VectorFloatAttribute::value() (" __HERE__ ")");
    // signature to use in the veto list: std::vector<float> HepMC3::VectorFloatAttribute::value()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:780:24
    t.method("value", static_cast<std::vector<float> (HepMC3::VectorFloatAttribute::*)()  const>(&HepMC3::VectorFloatAttribute::value));

    DEBUG_MSG("Adding wrapper for void HepMC3::VectorFloatAttribute::set_value(const std::vector<float> &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::VectorFloatAttribute::set_value(const std::vector<float> &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:785:10
    t.method("set_value", static_cast<void (HepMC3::VectorFloatAttribute::*)(const std::vector<float> &) >(&HepMC3::VectorFloatAttribute::set_value));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::VectorFloatAttribute>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_VectorFloatAttribute(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_VectorFloatAttribute(module));
}
