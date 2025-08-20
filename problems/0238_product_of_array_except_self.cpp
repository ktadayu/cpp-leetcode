#include "common.hpp"

vector<int> productExceptSelf(vector<int> &nums) {
  size_t n = nums.size();
  vector<int> res(n, 1);
  int curr = 1;
  for (size_t i = 0; i < n; ++i) {
    res[i] = curr;
    curr *= nums[i];
  }
  curr = 1;
  for (int i = n - 1; i >= 0; --i) {
    res[i] *= curr;
    curr *= nums[i];
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> v = productExceptSelf(nums);
  print_vector(v);
  return 0;
}
