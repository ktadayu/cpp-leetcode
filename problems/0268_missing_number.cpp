#include "common.hpp"

int missingNumber(vector<int> &nums) {
  int n = nums.size();
  int res = 0;
  int tmp = 0;
  for (int i = 0; i <= n; ++i) {
    res ^= i;
    if (i != n) {
      tmp ^= nums[i];
    }
  }
  return res ^ tmp;
}

int main() {
  vector<int> nums = {4, 3, 2, 1};
  int k = missingNumber(nums);

  cout << k << endl;

  return 0;
}
