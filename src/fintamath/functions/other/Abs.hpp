#pragma once

#include "fintamath/core/IArithmetic.hpp"
#include "fintamath/functions/IFunction.hpp"

namespace fintamath {
  class Abs : public IFunctionCRTP<Abs, IArithmetic> {
  public:
    Abs() = default;

    std::string toString() const override;

    std::string getClassName() const override;

  protected:
    MathObjectPtr call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const override;
  };
}
