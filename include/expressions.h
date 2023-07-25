#include "types.hpp"
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