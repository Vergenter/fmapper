#include "gtest/gtest.h"
#include "expressions.hpp"
#include "operations.hpp"

class ExpressionsTest : public ::testing::Test
{
protected:
    Array256 a{1, 2, 3, 4};
    Array256 b{5, 6, 7, 8};
    Array256 c{6, 8, 10, 12}; // a + b
};

TEST_F(ExpressionsTest, ConstantExpression)
{
    ConstantExpression const_expr(a);
    Array256 result = const_expr.evaluate(b); // ignore input
    ASSERT_EQ(result, a);
}

TEST_F(ExpressionsTest, VariableExpression)
{
    VariableExpression var_expr;
    Array256 result = var_expr.evaluate(a);
    ASSERT_EQ(result, a); // return input
}

TEST_F(ExpressionsTest, BinaryOperationExpressionAdd)
{
    auto constant1 = std::make_unique<ConstantExpression>(a);
    auto constant2 = std::make_unique<ConstantExpression>(b);

    BinaryOperationExpression add_expr(add, std::move(constant1), std::move(constant2));

    Array256 result = add_expr.evaluate(a); // ignore input
    ASSERT_EQ(result, c);
}
