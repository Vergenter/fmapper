#include "types.hpp"
#include "expressions.hpp"
#include "operations.hpp"
#include <numeric>
// Will be used in future!
// constexpr Array256 generate_correct_result()
// {
//   Array256 table{};
//   for (int i = 0; i < 256; ++i)
//   {
//     table[i] = (i >= 'a' && i <= 'z') ? i - 'a' + 'A' : i;
//   }
//   return table;
// }

// constexpr Array256 CORRECT_RESULT = generate_correct_result();

int main()
{
  Array256 a;
  std::fill(a.begin(), a.end(), 5);
  Array256 xs;
  std::iota(xs.begin(), xs.end(), 0);

  auto constant1 = std::make_unique<ConstantExpression>(a);
  auto constant2 = std::make_unique<VariableExpression>();

  BinaryOperationExpression add_expr(add, std::move(constant1), std::move(constant2));

  Array256 result = add_expr.evaluate(xs);
}