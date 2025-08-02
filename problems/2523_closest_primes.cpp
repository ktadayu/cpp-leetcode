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

vector<int> closestPrimes(int left, int right) {
  vector<int> v = sieve(right);
  auto it = lower_bound(v.begin(), v.end(), left);
  int idx_l = it - v.begin();
  vector<int> res = {-1, -1};
  if (v.size() - idx_l <= 1) {
    return res;
  }
  int mn = INT_MAX;
  int curr = 0;
  for (size_t i = idx_l; i < v.size() - 1; ++i) {
    curr = v[i + 1] - v[i];
    if (curr < mn) {
      mn = min(mn, curr);
      res = {v[i], v[i + 1]};
    }
  }
  return res;
}

int main() {
  int left = 150;
  int right = 401;
  vector<int> v = closestPrimes(left, right);
  print_vector(v);

  return 0;
}
