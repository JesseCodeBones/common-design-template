#include <algorithm>
#include <iostream>
using namespace std;
void sort(int x[], int y[], int m, int n) {
  for (size_t i = 0; i < m; i++) {
    if (x[i] > y[0]) {
      swap(x[i], y[0]);
    }
    // 将Y[0]放在合适位置
    int first = y[0];
    size_t k;
    for (k = 1; k < n && y[k] < first; k++) {
      y[k - 1] = y[k];
    }
    y[k - 1] = first;
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int, char **) {
  int X[] = {1, 4, 7, 8, 10};
  int Y[] = {2, 3, 9};
  sort(X, Y, sizeof(X) / sizeof(X[0]), sizeof(Y) / sizeof(Y[0]));
  cout << "X: ";
  printArray(X, sizeof(X) / sizeof(X[0]));
  cout << "Y: ";
  printArray(Y, sizeof(Y) / sizeof(Y[0]));
}
