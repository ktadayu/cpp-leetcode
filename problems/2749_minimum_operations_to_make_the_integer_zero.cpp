#include "common.hpp"

int makeTheIntegerZero(int num1, int num2) {
  if (num1 == 0) {
    return 0;
  }

  const long long mx = 1LL << 60;
  if (num2 > 0) {
    for (int k = 0; num1 / num2 >= (k + 1); ++k) {
      long long n = num1 - k * num2;
      cout << n << endl;
      int l = __builtin_popcountll(n);
      if (l <= k && k <= n && n / mx <= k) {
        return k;
      }
    }
    return -1;
  }

  for (int k = 0;; ++k) {
    long long n = num1 - k * num2;
    if (n > mx && n / mx > (k + 1)) {
      return -1;
    }
    int l = __builtin_popcountll(n);
    if (l <= k && k < n && n / mx <= k) {
      return k;
    }
  }
}

int main() {
  int num1 = 1000000000;
  int num2 = 0;
  int res = makeTheIntegerZero(num1, num2);

  cout << res << endl;

  return 0;
}
