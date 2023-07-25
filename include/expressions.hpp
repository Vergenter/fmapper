#include "types.hpp"
#include <functional>
#include <memory>
struct Expression
{
  virtual ~Expression() {}
  virtual Array256 evaluate(const Array256 &x) = 0;
};

// Leaf node for constant values
struct ConstantExpression : public Expression
{
  Array256 value;
  ConstantExpression(Array256 value) : value(value) {}
  Array256 evaluate(const Array256 &_) override { return value; }
};

// Leaf node for variable values
struct VariableExpression : public Expression
{
  VariableExpression() {}
  Array256 evaluate(const Array256 &x) override { return x; }
};

struct BinaryOperationExpression : public Expression
{
  std::function<Array256(Array256, Array256)> operation;
  std::unique_ptr<Expression> operand1;
  std::unique_ptr<Expression> operand2;
  BinaryOperationExpression(
      std::function<Array256(Array256, Array256)> operation,
      std::unique_ptr<Expression> operand1,
      std::unique_ptr<Expression> operand2)
      : operation(operation), operand1(std::move(operand1)),
        operand2(std::move(operand2)) {}
  Array256 evaluate(const Array256 &x) override
  {
    return operation(operand1->evaluate(x), operand2->evaluate(x));
  }
};