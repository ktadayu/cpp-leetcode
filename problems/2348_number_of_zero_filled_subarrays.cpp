#include "common.hpp"

long long zeroFilledSubarray(vector<int> &nums) {
  int cnt = 0;
  int curr_cnt = 0;
  long long res = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      curr_cnt++;
      cnt = max(cnt, curr_cnt);
    } else if (curr_cnt >= 1) {
      res += curr_cnt * (curr_cnt + 1) / 2;
      curr_cnt = 0;
    }
    if (i == nums.size() - 1 && curr_cnt >= 1) {
      res += curr_cnt * (curr_cnt + 1) / 2;
    }
  }

  return res;
}

int main() {
  // vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
  //  vector<int> nums = {0, 0, 0, 2, 0, 0};
  vector<int> nums = {2, 10, 2019};
  long long k = zeroFilledSubarray(nums);
  cout << k << endl;

  return 0;
}
