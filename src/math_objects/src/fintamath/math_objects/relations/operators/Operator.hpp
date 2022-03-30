#pragma once

#include "fintamath/math_objects/nodes/numbers/Rational.hpp"
#include "fintamath/math_objects/relations/Relation.hpp"

namespace fintamath {
  class Operator : public Relation {
  public:
    explicit Operator(const std::string &strOper);

    Rational solve(const Rational &lhs, const Rational &rhs, int64_t precision) const;

    std::string toString() const override;

  private:
    char name;
  };

  namespace types {
    bool isOperator(const std::string &str);
  }
}
