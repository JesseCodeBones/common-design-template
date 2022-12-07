#include <cstdlib>
#include <iostream>
// https://www.techiedelight.com/find-index-0-replaced-get-maximum-length-sequence-of-continuous-ones/
void findPos(int arr[], unsigned int length) {
  int cache = 0;
  int cacheIndex = 0;
  for (int i = 0; i < length; i++) {
    int before = 0;
    int after = 0;
    if (arr[i] == 0) {
      for (int j = (i-1); j > 0 && arr[j] == 1; j--) {
        before++;
      }
      for (int j = (i+1); j < length && arr[j] == 1; j++) {
        after++;
      }
      if (cache < (before + after)) {
        cache = (before + after);
        cacheIndex = i;
      }
    }
  }
  std::cout << "find position=" << cacheIndex << " length=" << cache+1
            << std::endl;
}

int main(int, char **) {
  int arr[] = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1};
  findPos(arr, sizeof(arr) / sizeof(arr[0]));
}
