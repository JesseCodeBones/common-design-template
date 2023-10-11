#include <gtest/gtest.h>
#include "../src/Constexpr.hpp"
TEST(emscripten_sdl2_framework_test, constexpr_better_than_const) {
  constFun();
  constFun();
  constExprFun();
}