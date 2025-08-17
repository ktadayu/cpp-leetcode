#include "common.hpp"

bool canJump(vector<int> &nums) {
  int n = nums.size();
  int reachable = 0;
  for (int i = 0; i <= reachable && i < n; ++i) {
    reachable = max(i + nums[i], reachable);
    if (n - 1 <= reachable) {
      return true;
    }
  }
  return n - 1 >= reachable;
}
int main() {
  vector<int> nums = {3, 2, 1, 0, 4};
  bool res = canJump(nums);
  cout << res << endl;

  return 0;
}
