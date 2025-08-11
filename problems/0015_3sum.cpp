#include "common.hpp"

vector<vector<int>> threeSum(vector<int> &nums) {
  int n = nums.size();
  if (n < 3) {
    return vector<vector<int>>{};
  }
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  int i = 0;
  int fixed = nums[i];
  while (fixed <= 0 && i < n) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      ++i;
      if (i >= n) {
        break;
      }
      fixed = nums[i];
      continue;
    }
    if (i + 2 < n) {
      int a = fixed + nums[i + 1] + nums[i + 2];
      if (a > 0) {
        break;
      }
    }
    if (i < n - 2) {
      int b = fixed + nums[n - 1] + nums[n - 2];
      if (b < 0) {
        ++i;
        fixed = nums[i];
        continue;
      }
    }

    for (int l = i + 1, r = n - 1; l < r;) {
      int s = fixed + nums[l] + nums[r];
      if (s < 0) {
        ++l;
      } else if (s > 0) {
        --r;
      } else {
        res.push_back({fixed, nums[l], nums[r]});
        while (l < r && nums[l] == nums[l + 1] && l + 1 < n) {
          ++l;
        }
        while (l < r && nums[r] == nums[r - 1]) {
          --r;
        }
        ++l;
        --r;
      }
    }
    ++i;
    if (i < n) {
      fixed = nums[i];
    } else {
      break;
    }
  }
  return res;
}

int main() {
  vector<int> nums = {-1, -2, -4, -5, 0, 5, 2, 1, 1, 3, 10};
  vector<vector<int>> v = threeSum(nums);
  print_vector(v);
  return 0;
}
