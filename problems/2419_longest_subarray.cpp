#include "common.hpp"

// 以下の実装は遅い
// mxを更新しながらカウントしていけば速い
// mxが始めて更新されたときにカウントを1にリセットする感じで
int longestSubarray(vector<int> &nums) {
  int n = nums.size();
  int mx = *max_element(nums.begin(), nums.end());
  int res = 0;
  int curr_l = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == mx) {
      ++curr_l;
      res = max(res, curr_l);
      continue;
    }

    curr_l = 0;
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  int k = longestSubarray(nums);
  cout << k << endl;
  return 0;
}
