#include <iostream>

using namespace std;

void merge(int X[], int Y[], int m, int n) {

  int B[m + n];
  for (size_t i = m + n; i > 0; i--) {
    if (X[m-1] > Y[n-1]) {
      B[i - 1] = X[m - 1];
      m--;
    } else {
      B[i - 1] = Y[n - 1];
      n--;
    }
  }

  for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
    printf("%d \n", B[i]);
  }
}

int main(int, char **) {
  int X[] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
  int Y[] = {1, 8, 9, 10, 15};

  // remove slot
  int k = 0;
  for (size_t i = 0; i < sizeof(X) / sizeof(X[0]); i++) {
    if (X[i] != 0) {
      X[k] = X[i];
      k++;
    }
  }
  merge(X, Y, k, sizeof(Y) / sizeof(Y[0]));
}
