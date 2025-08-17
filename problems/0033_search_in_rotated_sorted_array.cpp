#include "common.hpp"
// todo:clean up
int search(vector<int> &nums, int target) {
  int n = nums.size();
  if (n == 1) {
    if (nums[0] == target) {
      return 0;
    } else {
      return -1;
    }
  }
  int l = 0, r = n - 1;
  int mid = (l + r) / 2;

  while (l < r) {
    if (nums[l] == target) {
      return l;
    }
    if (nums[r] == target) {
      return r;
    }
    if (nums[mid] == target) {
      return mid;
    }

    // 左の区間が連続
    if (nums[l] < nums[mid]) {
      if (nums[mid] < target || target < nums[l]) {
        l = mid + 1;
        mid = (l + r) / 2;
        continue;
      } else {
        r = mid;
        mid = (l + r) / 2;
        continue;
      }
    }
    // 右の区間が連続
    if (nums[mid] < nums[r]) {
      if (target > nums[r] || target < nums[mid]) {
        r = mid;
        mid = (l + r) / 2;
        continue;
      } else {
        l = mid + 1;
        mid = (l + r) / 2;
        continue;
      }
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {5, 1, 2, 3, 4};
  int target = 1;
  int k = search(nums, target);
  cout << k << endl;

  return 0;
}
