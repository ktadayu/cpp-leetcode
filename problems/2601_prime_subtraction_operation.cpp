#include "common.hpp"
#include <cmath>

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

bool primeSubOperation(vector<int> &nums) {
  int n = nums.size();
  int mx = *max_element(nums.begin(), nums.end());
  vector<int> v = sieve(mx + 1);
  int res = true;
  for (int i = 0; i < n; ++i) {
    int c = nums[i];
    if (i == 0) {
      // cを未満の素数, なければ-1
      int p = getFloor(v, c);
      if (p == -1) {
        continue;
      }
      nums[i] = c - p;
      continue;
    }

    if (c - nums[i - 1] <= 0) {
      cout << "i=" << i << endl;
      cout << "c=" << c << endl;
      cout << "nums[i-1]=" << nums[i - 1] << endl;
      print_vector(nums);
      return false;
    }
    int p = getFloor(v, c - nums[i - 1]);
    if (p == -1) {
      continue;
    }
    nums[i] = c - p;
  }
  return res;
}

int main() {

  vector<int> nums = {5, 8, 3};

  bool b = primeSubOperation(nums);
  cout << b << endl;

  return 0;
}
