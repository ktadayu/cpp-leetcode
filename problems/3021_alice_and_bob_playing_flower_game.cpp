#include "common.hpp"

long long flowerGame(int n, int m) {
  long long res = 0;
  long long odd_n = (n + 1) / 2, odd_m = (m + 1) / 2, even_n = n / 2,
            even_m = m / 2;

  res = odd_n * even_m + odd_m * even_n;

  return res;
}

int main() {

  long long res = flowerGame(3, 2);
  cout << res << endl;

  return 0;
}
