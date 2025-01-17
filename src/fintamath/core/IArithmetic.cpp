#include "fintamath/core/IArithmetic.hpp"

#include "fintamath/helpers/MultiMethod.hpp"
#include "fintamath/numbers/Integer.hpp"
#include "fintamath/numbers/Rational.hpp"

namespace fintamath {
  auto initMultiDiv() {
    helpers::MultiMethod<ArithmeticPtr(const IArithmetic &, const IArithmetic &)> multiDiv;
    multiDiv.add<Integer, Integer>([](const Integer &lhs, const Integer &rhs) {
      auto res = (Rational(lhs) / Rational(rhs)).simplify();
      return helpers::cast<IArithmetic>(res);
    });
    return multiDiv;
  }

  const auto mDiv = initMultiDiv();

  ArithmeticPtr multiDiv(const IArithmetic &lhs, const IArithmetic &rhs) {
    return mDiv(lhs, rhs);
  }
}
