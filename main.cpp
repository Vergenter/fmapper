#include <array>
#include <cstdint>
#include <functional>
#include <memory>
#include <stack>
#include <vector>
constexpr std::array<char, 256> create_lookup_table() {
  std::array<char, 256> table{};
  for (int i = 0; i < 256; ++i) {
    table[i] = (i >= 'a' && i <= 'z') ? i - 'a' + 'A' : i;
  }
  return table;
}

constexpr std::array<char, 256> to_upper = create_lookup_table();

using Array256 = std::array<uint8_t, 256>;

auto add = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::plus<>());
  return result;
};

auto subtract = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::minus<>());
  return result;
};

auto multiply = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::multiplies<>());
  return result;
};

auto divide = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) {
                   return x / std::max(y, static_cast<uint8_t>(1));
                 });
  return result;
};

auto modulo = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) {
                   return x % std::max(y, static_cast<uint8_t>(1));
                 });
  return result;
};

auto bitwise_and = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_and<>());
  return result;
};

auto bitwise_or = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_or<>());
  return result;
};

auto bitwise_xor = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_xor<>());
  return result;
};

auto left_shift = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) {
                   return x << std::min(static_cast<uint8_t>(7), y);
                 });
  return result;
};

auto right_shift = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) {
                   return x >> std::min(static_cast<uint8_t>(7), y);
                 });
  return result;
};

auto less_than = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x < y ? 1 : 0; });
  return result;
};

auto less_than_or_equal_to = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x <= y ? 1 : 0; });
  return result;
};

auto greater_than = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x > y ? 1 : 0; });
  return result;
};

auto greater_than_or_equal_to = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x >= y ? 1 : 0; });
  return result;
};

auto equal_to = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x == y ? 1 : 0; });
  return result;
};

auto not_equal_to = [](Array256 a, Array256 b) {
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y) { return x != y ? 1 : 0; });
  return result;
};

struct Expression {
  virtual ~Expression() {}
  virtual Array256 evaluate(const Array256 &x) = 0;
};

// Leaf node for constant values
struct ConstantExpression : public Expression {
  Array256 value;
  ConstantExpression(Array256 value) : value(value) {}
  Array256 evaluate(const Array256 &x) override { return value; }
};

// Leaf node for variable values
struct VariableExpression : public Expression {
  VariableExpression() {}
  Array256 evaluate(const Array256 &x) override { return x; }
};

// Interior node for binary operations
struct BinaryOperationExpression : public Expression {
  std::function<Array256(Array256, Array256)> operation;
  std::unique_ptr<Expression> operand1;
  std::unique_ptr<Expression> operand2;
  BinaryOperationExpression(
      std::function<Array256(Array256, Array256)> operation,
      std::unique_ptr<Expression> operand1,
      std::unique_ptr<Expression> operand2)
      : operation(operation), operand1(std::move(operand1)),
        operand2(std::move(operand2)) {}

  Array256 evaluate(const Array256 &x) override {
    return operation(operand1->evaluate(x), operand2->evaluate(x));
  }
};

// Now an individual is just a single expression tree
typedef std::unique_ptr<Expression> Individual;

Array256 evaluate_individual(const Individual &individual, const Array256 &x) {
  return individual->evaluate(x);
}

int main() { ; }