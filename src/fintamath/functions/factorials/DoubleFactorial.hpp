#pragma once

#include "fintamath/functions/IOperator.hpp"
#include "fintamath/numbers/Integer.hpp"

namespace fintamath {
  class DoubleFactorial : public IOperatorCRTP<DoubleFactorial, Integer> {
  public:
    DoubleFactorial();

    std::string toString() const override;

    std::string getClassName() const override;

  protected:
    MathObjectPtr call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const override;
  };
}
