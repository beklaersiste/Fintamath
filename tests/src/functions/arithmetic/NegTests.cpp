#include "gtest/gtest.h"

#include "fintamath/functions/arithmetic/Neg.hpp"

#include "fintamath/literals/Variable.hpp"
#include "fintamath/numbers/Rational.hpp"

using namespace fintamath;

TEST(NegTests, toStringTest) {
  EXPECT_EQ(Neg().toString(), "-");
}

TEST(NegTests, getFunctionTypeTest) {
  EXPECT_EQ(Neg().getFunctionType(), IFunction::Type::Unary);
}

TEST(NegTests, getOperatorPriorityTest) {
  EXPECT_EQ(Neg().getOperatorPriority(), IOperator::Priority::PrefixUnary);
}

TEST(NegTests, callTest) {
  EXPECT_EQ(Neg()(Integer(3))->toString(), "-3");
  EXPECT_EQ(Neg()(Rational(5, 2))->toString(), "-5/2");

  EXPECT_ANY_THROW(Neg()(Variable("a")));

  std::unique_ptr<IOperator> o = std::make_unique<Neg>();
  EXPECT_ANY_THROW((*o)(Integer(1), Rational(2, 3)));
  EXPECT_ANY_THROW((*o)());
  EXPECT_ANY_THROW((*o)(Integer(1), Integer(1), Integer(1)));
}
