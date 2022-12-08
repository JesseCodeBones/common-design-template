#include <iostream>
#include <sstream>
#include <utility>

void moveZeroEnd(int a[], int length) {
  int indexNe = 0;
  for (int i = 0; i < length; ++i) {
    if (a[i] != 0) {
      std::swap(a[i], a[indexNe]);
      indexNe++;
    }
  }
  std::stringstream stm;
  for (int i = 0; i < length; ++i) {
    stm << " " << a[i] << " ";
  }
  stm << "\n";
  std::cout << stm.str();
}

int main(int, char **) {
  int a[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
  moveZeroEnd(a, sizeof(a) / sizeof(a[0]));
}
