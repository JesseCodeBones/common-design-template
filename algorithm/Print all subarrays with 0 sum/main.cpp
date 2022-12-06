#include <iostream>
#include <vector>
using namespace std;

void findSubZeroVector(vector<int> &vct) {
  for (size_t i = 0; i < vct.size(); i++) {
    int sum = 0;
    for (size_t j = i; j < vct.size(); j++) {
      sum += vct[j];
      if (sum == 0) {
        cout << "found sub array zero: started at " << i << ", end at " << j
             << endl;
      }
    }
  }
}

int main(int, char **) {
  std::vector<int> vct{1, 3, -7, 3, 2, 3, 1, -3, -2, -2};
  findSubZeroVector(vct);
}
