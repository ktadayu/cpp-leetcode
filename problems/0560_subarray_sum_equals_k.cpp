#include "common.hpp"

int subarraySum(vector<int> &nums, int k) {
  unordered_map<int, int> um;
  um[0] = 1;
  int sum = 0, cnt = 0;
  for (int num : nums) {
    sum += num;
    cnt = um[sum - k] + cnt;
    ++um[sum];
  }
  return cnt;
}

int main() {
  vector<int> nums = {1, 2, 3};
  int k = subarraySum(nums, 3);
  cout << k << endl;

  return 0;
}
