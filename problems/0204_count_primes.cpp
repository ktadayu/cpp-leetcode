#include "common.hpp"

// 素数列挙
vector<int> sieve(int n) {
  vector<bool> isp(n + 1, true);
  vector<int> res;
  res.reserve(n / 2);
  isp[0] = false;
  isp[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isp[i]) {
      for (int j = i; i * j < n + 1; ++j) {
        isp[i * j] = false;
      }
    }
  }
  for (int i = 0; i < n + 1; ++i) {
    if (isp[i]) {
      res.push_back(i);
    }
  }
  return res;
}

int countPrimes(int n) {
  vector<int> v = sieve(n);
  return v.size();
}

int main() {
  int n = 1;
  int k = countPrimes(n);
  cout << k << endl;

  return 0;
}
