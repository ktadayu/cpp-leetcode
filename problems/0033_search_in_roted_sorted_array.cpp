#include "common.hpp"

int search(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  int mid = (left + right) / 2;
  int ans = -1;
  while (left != right) {
    if (nums[left] == target) {
      return left;
    }
    if (nums[right] == target) {
      return right;
    }
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] < target) {
      left = midi + 1;
    }
  }
}

int main() { return 0; }
