#include "gtest/gtest.h"

#include "fintamath/functions/comparison/Less.hpp"

#include "fintamath/literals/Variable.hpp"
#include "fintamath/numbers/Rational.hpp"

using namespace fintamath;

TEST(LessTests, toStringTest) {
  EXPECT_EQ(Less().toString(), "<");
}

TEST(LessTests, getFunctionTypeTest) {
  EXPECT_EQ(Less().getFunctionType(), IFunction::Type::Binary);
}

TEST(LessTests, getOperatorPriorityTest) {
  EXPECT_EQ(Less().getOperatorPriority(), IOperator::Priority::Comparison);
}

TEST(LessTests, callTest) {
  EXPECT_EQ(Less()(Integer(5), Integer(3))->toString(), "false");
  EXPECT_EQ(Less()(Integer(3), Integer(5))->toString(), "true");
  EXPECT_EQ(Less()(Integer(3), Integer(3))->toString(), "false");
  EXPECT_EQ(Less()(Integer(3), Rational(3, 1))->toString(), "false");
  EXPECT_EQ(Less()(Rational(5, 2), Integer(2))->toString(), "false");

  std::unique_ptr<IOperator> o = std::make_unique<Less>();
  EXPECT_ANY_THROW((*o)(Integer(3), Variable("a")));
  EXPECT_ANY_THROW((*o)(Variable("a"), Variable("a")));
  EXPECT_ANY_THROW((*o)(Integer(1)));
  EXPECT_ANY_THROW((*o)(Rational(2, 3)));
  EXPECT_ANY_THROW((*o)());
  EXPECT_ANY_THROW((*o)(Integer(1), Integer(1), Integer(1)));
}
