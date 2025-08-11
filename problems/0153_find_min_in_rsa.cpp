#include "common.hpp"
int findMin(vector<int> &nums) {
  int left = 0, right = nums.size() - 1;
  int mid = (left + right) / 2;
  while (left != right) {
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    }
    if (nums[mid] <= nums[right]) {
      right = mid;
    }
    mid = (left + right) / 2;
  }
  return nums[left];
}
int main() {
  vector<int> nums = {11, 13, 15, 17};
  int k = findMin(nums);
  cout << k << endl;

  return 0;
}
