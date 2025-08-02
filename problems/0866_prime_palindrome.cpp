#include "common.hpp"

// 10進数のxの各桁の値を逆転させたものを返す
// int reverse_num(int x) {
//  int tmp = x;
//  long rev = 0;
//  while (x > 0) {
//    rev = rev * 10 + (x % 10);
//    x /= 10;
//  }
//  return rev;
//}
//
// int primePalindrome(int n) {
//  // 2~2*10^8までの素数を列挙
//  vector<int> v = sieve(2 * 1e8);
//  auto it = lower_bound(v.begin(), v.end(), n);
//  int idx = it - v.begin();
//  int res = 0;
//  for (size_t i = idx; i < v.size(); ++i) {
//    int a = reverse_num(v[i]);
//    if (v[i] == a) {
//      return v[i];
//    }
//  }
//  return 0;
//}

int main() {
  int n = 13;
  int k = primePalindrome(n);
  cout << k << endl;

  return 0;
}
