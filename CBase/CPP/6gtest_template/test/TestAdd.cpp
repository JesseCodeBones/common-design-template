#include "../src/MyMath.hpp"
#include <gtest/gtest.h>
TEST(HelloTest, BasicAssertions) {
  int a = 1, b = 2;
  MyMath myMath;
  ASSERT_TRUE(myMath.add(a, b) == 3);
}