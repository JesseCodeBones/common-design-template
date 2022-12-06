#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <size_t A_SIZE> void findSameElement(array<int, A_SIZE> &ary) {
  unordered_map<int, int> map = {};
  for (size_t i = 0; i < A_SIZE; i++) {
    if (map.find(ary[i]) == end(map)) {
      map[ary[i]] = i;
    } else {
      cout << "find duplicated element:" << ary[i] << endl;
    }
  }
}

int main(int, char **) {
  std::array<int, 6> ary{1, 2, 3, 3, 4, 1};
  findSameElement(ary);
}
