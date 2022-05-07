#include "fintamath/functions/Function.hpp"

namespace fintamath {
  class Log : public FunctionImpl<Log> {
  public:
    Log() = default;

    std::string toString() const override;

    MathObjectPtr operator()(const MathObject &lhs, const MathObject &rhs) const;

  protected:
    bool equals(const Log &rhs) const override;

    MathObjectPtr call(const std::vector<std::reference_wrapper<const MathObject>> &argsVect) const override;
  };
}