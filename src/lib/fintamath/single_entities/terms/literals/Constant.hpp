#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <string>

#include "single_entities/ISingleEntity.hpp"
#include "single_entities/terms/numbers/Rational.hpp"

class Constant : public ISingleEntity {
public:
  explicit Constant(const std::string &);

  Rational toRational() const;
  std::string toString() const override;
  std::string getTypeName() const override;

private:
  std::string constant;
};

namespace isType {
bool isConstant(const std::string &);
}

#endif // CONSTANT_HPP