#include "common.hpp"

bool partitionArray(vector<int> &nums, int k) {
  int n = nums.size();
  if (n % k != 0) {
    return false;
  }
  int q = n / k;
  unordered_map<int, int> um;
  int mx_freq = 0;
  for (int i = 0; i < n; ++i) {
    um[nums[i]]++;
    mx_freq = max(mx_freq, um[nums[i]]);
  }
  return (mx_freq <= q);
}

int main() { return 0; }
