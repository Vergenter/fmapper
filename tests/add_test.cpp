#include "gtest/gtest.h"
#include "operations.hpp"

TEST(AddTest, HandlesZero)
{
    Array256 a{0}, b{0};
    Array256 result = add(a, b);

    ASSERT_EQ(result[0], 0);
}

TEST(AddTest, AddsValues)
{
    Array256 a{1, 2, 3}, b{4, 5, 6};
    Array256 expected{5, 7, 9};

    Array256 result = add(a, b);

    ASSERT_EQ(result, expected);
}
