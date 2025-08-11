#include "common.hpp"

int minSubArrayLen(int target, vector<int> &nums) {
  int n = nums.size();
  int res = n + 1;
  int curr = 0;
  for (int l = 0, r = 0; r < n; r++) {
    curr += nums[r];
    cout << "curr_status" << endl;
    cout << "curr=" << curr << endl;
    cout << "l= " << l << endl;
    cout << "r=" << r << endl;
    while (curr >= target && l <= r) {
      cout << "curr_res:" << res << endl;
      cout << "r-l+1:" << r - l + 1 << endl;
      res = min(res, r - l + 1);
      cout << "curr_res:" << res << endl;
      if (res == 1) {
        return 1;
      }
      curr -= nums[l];
      ++l;
    }
  }
  return res = (res == n + 1) ? 0 : res;
}

int main() {
  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  int k = minSubArrayLen(target, nums);
  cout << k << endl;
  return 0;
}
