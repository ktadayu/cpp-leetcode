#include "common.hpp"

int minOperations(vector<int> &nums) {

  if (n == 1) {
    return 0;
  }
  int n = nums.size();
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i] != nums[i + 1]) {
      return 1;
    }
  }
  return 0;
}

int main() { return 0; }
