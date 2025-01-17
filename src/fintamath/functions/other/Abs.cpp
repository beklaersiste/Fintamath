#include "fintamath/functions/other/Abs.hpp"

#include "fintamath/numbers/NumericFunctions.hpp"

namespace fintamath {
  std::string Abs::toString() const {
    return "abs";
  }

  std::string Abs::getClassName() const {
    return "Abs";
  }

  MathObjectPtr Abs::call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const {
    return abs(helpers::Converter::convert(argsVect.at(0), Rational())->to<Rational>()).simplify();
  }
}
