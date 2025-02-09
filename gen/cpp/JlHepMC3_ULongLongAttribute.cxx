// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::ULongLongAttribute> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::ULongLongAttribute> : std::false_type { };
template<> struct SuperType<HepMC3::ULongLongAttribute> { typedef HepMC3::Attribute type; };
}

// Class generating the wrapper for type HepMC3::ULongLongAttribute
// signature to use in the veto file: HepMC3::ULongLongAttribute
struct JlHepMC3_ULongLongAttribute: public Wrapper {

  JlHepMC3_ULongLongAttribute(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::ULongLongAttribute (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:617:7
    jlcxx::TypeWrapper<HepMC3::ULongLongAttribute>  t = jlModule.add_type<HepMC3::ULongLongAttribute>("HepMC3!ULongLongAttribute",
      jlcxx::julia_base_type<HepMC3::Attribute>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::ULongLongAttribute>>(new jlcxx::TypeWrapper<HepMC3::ULongLongAttribute>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::ULongLongAttribute::ULongLongAttribute(unsigned long long) (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:624:5
    t.constructor<unsigned long long>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool HepMC3::ULongLongAttribute::from_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::ULongLongAttribute::from_string(const std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:627:10
    t.method("from_string", static_cast<bool (HepMC3::ULongLongAttribute::*)(const std::string &) >(&HepMC3::ULongLongAttribute::from_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::ULongLongAttribute::to_string(std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::ULongLongAttribute::to_string(std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:634:10
    t.method("to_string", static_cast<bool (HepMC3::ULongLongAttribute::*)(std::string &)  const>(&HepMC3::ULongLongAttribute::to_string));

    DEBUG_MSG("Adding wrapper for unsigned long long HepMC3::ULongLongAttribute::value() (" __HERE__ ")");
    // signature to use in the veto list: unsigned long long HepMC3::ULongLongAttribute::value()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:640:24
    t.method("value", static_cast<unsigned long long (HepMC3::ULongLongAttribute::*)()  const>(&HepMC3::ULongLongAttribute::value));

    DEBUG_MSG("Adding wrapper for void HepMC3::ULongLongAttribute::set_value(const unsigned long long &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::ULongLongAttribute::set_value(const unsigned long long &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:645:10
    t.method("set_value", static_cast<void (HepMC3::ULongLongAttribute::*)(const unsigned long long &) >(&HepMC3::ULongLongAttribute::set_value));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::ULongLongAttribute>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_ULongLongAttribute(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_ULongLongAttribute(module));
}
