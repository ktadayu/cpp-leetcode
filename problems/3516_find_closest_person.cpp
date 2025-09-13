#include "common.hpp"

int abs(int n, int m) {
  if (n <= m) {
    return m - n;
  }
  if (m < n) {
    return n - m;
  }
  return 0;
}

int findClosest(int x, int y, int z) {
  int d_13 = abs(x, z);
  int d_23 = abs(y, z);

  return d_13 < d_23 ? 1 : d_13 > d_23 ? 2 : 0;
}

int main() {
  int x = 2, y = 5, z = 3;
  int k = findClosest(x, y, z);

  cout << k << endl;

  return 0;
}
