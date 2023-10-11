#ifndef __jesse_best_practice__
#define __jesse_best_practice__
#include <array>
#include <iostream>
class JesseClassTest {
public:
  JesseClassTest() { std::cout << "construct\n"; }
};

static constexpr uint32_t a = 0;

class MyConstClass {
public:
  constexpr MyConstClass(int value) : data(value) {}

  constexpr int getValue() const { return data; }

private:
  int data = 42; // 这个断点是打不进去的，因为已经内联了
};

static void constFun() {
  static const JesseClassTest test; // 运行期间做初始化, 多次进入也是只执行一次
}

constexpr uint32_t conxtexprAdd(int a, int b) { return a + b; }

static void constExprFun() {
  static constexpr MyConstClass test(
      31); // 初始化在编译期间已经做好了，运行期间直接调用，不需要初始化
  constexpr uint32_t result = test.getValue();
  std::cout << result << std::endl;
  constexpr std::array<uint32_t, 3> list{1, 2, 3};
  constexpr uint32_t result2 = list.at(1);
  std::cout << result2 << std::endl;
  std::cout << conxtexprAdd(1, 2) << std::endl;
}
#endif