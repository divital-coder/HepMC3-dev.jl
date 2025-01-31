// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlHepMC3.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<HepMC3::StringAttribute> : std::false_type { };
  template<> struct DefaultConstructible<HepMC3::StringAttribute> : std::false_type { };
template<> struct SuperType<HepMC3::StringAttribute> { typedef HepMC3::Attribute type; };
}

// Class generating the wrapper for type HepMC3::StringAttribute
// signature to use in the veto file: HepMC3::StringAttribute
struct JlHepMC3_StringAttribute: public Wrapper {

  JlHepMC3_StringAttribute(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type HepMC3::StringAttribute (" __HERE__ ")");
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:343:7
    jlcxx::TypeWrapper<HepMC3::StringAttribute>  t = jlModule.add_type<HepMC3::StringAttribute>("HepMC3!StringAttribute",
      jlcxx::julia_base_type<HepMC3::Attribute>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<HepMC3::StringAttribute>>(new jlcxx::TypeWrapper<HepMC3::StringAttribute>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


    DEBUG_MSG("Adding wrapper for void HepMC3::StringAttribute::StringAttribute(const std::string &) (" __HERE__ ")");
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:355:5
    t.constructor<const std::string &>(/*finalize=*/jlcxx::finalize_policy::yes);

    DEBUG_MSG("Adding wrapper for bool HepMC3::StringAttribute::from_string(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::StringAttribute::from_string(const std::string &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:358:10
    t.method("from_string", static_cast<bool (HepMC3::StringAttribute::*)(const std::string &) >(&HepMC3::StringAttribute::from_string));

    DEBUG_MSG("Adding wrapper for bool HepMC3::StringAttribute::to_string(std::string &) (" __HERE__ ")");
    // signature to use in the veto list: bool HepMC3::StringAttribute::to_string(std::string &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:364:10
    t.method("to_string", static_cast<bool (HepMC3::StringAttribute::*)(std::string &)  const>(&HepMC3::StringAttribute::to_string));

    DEBUG_MSG("Adding wrapper for std::string HepMC3::StringAttribute::value() (" __HERE__ ")");
    // signature to use in the veto list: std::string HepMC3::StringAttribute::value()
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:370:17
    t.method("value", static_cast<std::string (HepMC3::StringAttribute::*)()  const>(&HepMC3::StringAttribute::value));

    DEBUG_MSG("Adding wrapper for void HepMC3::StringAttribute::set_value(const std::string &) (" __HERE__ ")");
    // signature to use in the veto list: void HepMC3::StringAttribute::set_value(const std::string &)
    // defined in /Users/apple/.julia/artifacts/e594d2eb58d058362f1ddc846f42621345899c63/include/HepMC3/Attribute.h:375:10
    t.method("set_value", static_cast<void (HepMC3::StringAttribute::*)(const std::string &) >(&HepMC3::StringAttribute::set_value));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<HepMC3::StringAttribute>> type_;
};
std::shared_ptr<Wrapper> newJlHepMC3_StringAttribute(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlHepMC3_StringAttribute(module));
}
