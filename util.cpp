#include <common.cpp>

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

// targetを超えない最大の要素をvectorから取得
int getFloor(const vector<int> &v, int target) {
  if (v.empty()) {
    return -1;
  }
  auto it = lower_bound(v.begin(), v.end(), target);
  if (it == v.begin()) {
    return -1;
  }
  --it;
  return *it;
}
