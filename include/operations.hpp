#include "types.hpp"
#include <functional>

inline Array256 add(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::plus<>());
  return result;
};

inline Array256 subtract(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::minus<>());
  return result;
};

inline Array256 multiply(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::multiplies<>());
  return result;
};

inline Array256 divide(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 {
                   return x / std::max(y, static_cast<uint8_t>(1));
                 });
  return result;
};

inline Array256 modulo(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 {
                   return x % std::max(y, static_cast<uint8_t>(1));
                 });
  return result;
};

inline Array256 bitwise_and(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_and<>());
  return result;
};

inline Array256 bitwise_or(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_or<>());
  return result;
};

inline Array256 bitwise_xor(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 std::bit_xor<>());
  return result;
};

inline Array256 left_shift(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 {
                   return x << std::min(static_cast<uint8_t>(7), y);
                 });
  return result;
};

inline Array256 right_shift(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 {
                   return x >> std::min(static_cast<uint8_t>(7), y);
                 });
  return result;
};

inline Array256 less_than(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x < y ? 1 : 0; });
  return result;
};

inline Array256 less_than_or_equal_to(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x <= y ? 1 : 0; });
  return result;
};

inline Array256 greater_than(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x > y ? 1 : 0; });
  return result;
};

inline Array256 greater_than_or_equal_to(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x >= y ? 1 : 0; });
  return result;
};

inline Array256 equal_to(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x == y ? 1 : 0; });
  return result;
};

inline Array256 not_equal_to(Array256 a, Array256 b)
{
  Array256 result;
  std::transform(a.begin(), a.end(), b.begin(), result.begin(),
                 [](uint8_t x, uint8_t y)
                 { return x != y ? 1 : 0; });
  return result;
};