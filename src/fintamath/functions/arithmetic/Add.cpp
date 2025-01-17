#include "fintamath/functions/arithmetic/Add.hpp"

namespace fintamath {
  Add::Add() : IOperatorCRTP(IOperator::Priority::Addition) {
  }

  std::string Add::toString() const {
    return "+";
  }

  std::string Add::getClassName() const {
    return "Add";
  }

  MathObjectPtr Add::call(const std::vector<std::reference_wrapper<const IMathObject>> &argsVect) const {
    return argsVect.at(0).get().to<IArithmetic>() + argsVect.at(1).get().to<IArithmetic>();
  }
}
