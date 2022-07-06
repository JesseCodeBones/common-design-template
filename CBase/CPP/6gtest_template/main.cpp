#include "src/MyMath.hpp"
#include <iostream>

int main(int, char **) {
  int a = 1, b = 2;
  MyMath mymath;
  std::cout << std::to_string(mymath.add(a, b)) << std::endl;
}
