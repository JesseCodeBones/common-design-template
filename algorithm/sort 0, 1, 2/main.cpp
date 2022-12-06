#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
void sort(vector<int> &vct) {
  int one = 0;
  int two = 0;
  for (int i : vct) {
    if (i == 1) {
      ++one;
    } else if (i == 2) {
      ++two;
    }
  }
  stringstream stm;
  for (size_t i = 0; i < (vct.size() - one - two); i++)
  {
    stm << " 0 ";
  }
  for (size_t i = 0; i < one; i++)
  {
    stm << " 1 ";
  }
  for (size_t i = 0; i < two; i++)
  {
    stm << " 2 ";
  }
  stm << "\n";
  std::cout << stm.str();
  
}
int main(int, char **) {
  vector<int> vct{0, 0, 1, 1, 0, 0, 2, 2, 2, 0};
  sort(vct);
}
