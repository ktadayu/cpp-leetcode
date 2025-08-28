#include "common.hpp"

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) {
    return b;
  } else {
    return gcd(b, r);
  }
}

int gcdOfOddEvenSums(int n) {

  int sumOdd = 0, sumEven = 0;
  for (int i = 0; i <= 2 * n; ++i) {
    if (i & 1) {
      sumOdd += i;
    } else {
      sumEven += i;
    }
  }

  return gcd(sumOdd, sumEven);
}

int main() {
  int n = 4;
  int k = gcdOfOddEvenSums(n);

  cout << k << endl;
  return 0;
}
