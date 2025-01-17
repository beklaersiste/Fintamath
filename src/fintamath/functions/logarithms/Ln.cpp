#include "fintamath/functions/logarithms/Ln.hpp"

#include "fintamath/numbers/NumericFunctions.hpp"

namespace fintamath {
  std::string Ln::toString() const {
    return "ln";
  }

  std::string Ln::getClassName() const {
    return "Ln";
  }

  MathObjectPtr Ln::call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const {
    constexpr int64_t defaultPrecision = 45;
    return ln(helpers::Converter::convert(argsVect.at(0), Rational())->to<Rational>(), defaultPrecision).simplify();
  }
}
