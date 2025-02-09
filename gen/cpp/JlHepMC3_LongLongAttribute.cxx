// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::LongLongAttribute> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::LongLongAttribute> : std::false_type { };
template<> struct SuperType<HepMC3::LongLongAttribute> { typedef HepMC3::Attribute type; };
}

// Class generating the wrapper for type HepMC3::LongLongAttribute
// signature to use in the veto file: HepMC3::LongLongAttribute
struct JlHepMC3_LongLongAttribute: public Wrapper {

  JlHepMC3_LongLongAttribute(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::LongLongAttribute (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:434:7
    jlcxx::TypeWrapper<HepMC3::LongLongAttribute>  t = jlModule.add_type<HepMC3::LongLongAttribute>("HepMC3!LongLongAttribute",
      jlcxx::julia_base_type<HepMC3::Attribute>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::LongLongAttribute>>(new jlcxx::TypeWrapper<HepMC3::LongLongAttribute>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::LongLongAttribute::LongLongAttribute(long long) (" __HERE__ ")");
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:441:5
    t.constructor<long long>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool HepMC3::LongLongAttribute::from_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::LongLongAttribute::from_string(const std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:444:10
    t.method("from_string", static_cast<bool (HepMC3::LongLongAttribute::*)(const std::string &) >(&HepMC3::LongLongAttribute::from_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::LongLongAttribute::to_string(std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::LongLongAttribute::to_string(std::string &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:451:10
    t.method("to_string", static_cast<bool (HepMC3::LongLongAttribute::*)(std::string &)  const>(&HepMC3::LongLongAttribute::to_string));

    DEBUG_MSG("Adding wrapper for long long HepMC3::LongLongAttribute::value() (" __HERE__ ")");
    // signature to use in the veto list: long long HepMC3::LongLongAttribute::value()
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:457:15
    t.method("value", static_cast<long long (HepMC3::LongLongAttribute::*)()  const>(&HepMC3::LongLongAttribute::value));

    DEBUG_MSG("Adding wrapper for void HepMC3::LongLongAttribute::set_value(const long long &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::LongLongAttribute::set_value(const long long &)
    // defined in /home/hurtbadly/.julia/artifacts/7594d64d7c28f9689b484bf4d09af6dbb8b5123c/include/HepMC3/Attribute.h:462:10
    t.method("set_value", static_cast<void (HepMC3::LongLongAttribute::*)(const long long &) >(&HepMC3::LongLongAttribute::set_value));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::LongLongAttribute>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_LongLongAttribute(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_LongLongAttribute(module));
}
