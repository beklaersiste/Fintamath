#include "fintamath/functions/logarithms/Lb.hpp"

#include "fintamath/numbers/NumericFunctions.hpp"

namespace fintamath {
  std::string Lb::toString() const {
    return "lb";
  }

  std::string Lb::getClassName() const {
    return "Lb";
  }

  MathObjectPtr Lb::call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const {
    constexpr int64_t defaultPrecision = 45;
    return lb(helpers::Converter::convert(argsVect.at(0), Rational())->to<Rational>(), defaultPrecision).simplify();
  }
}
