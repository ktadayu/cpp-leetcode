#include "common.hpp"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPI(i, start, end) for (int i = (start); i < (end); ++i)
#define RREPI(i, end, start) for (int i = (end) - 1; i >= start; --i)
#define EACH(i, is) for (auto &&i : (is))

vector<vector<int>> res;

void getPermutation(vector<int> &nums, int startIdx) {
  int n = nums.size();
  if (n == startIdx) {
    res.push_back(nums);
    return;
  }
  REPI(i, startIdx, n) {
    swap(nums[startIdx], nums[i]);
    getPermutation(nums, startIdx + 1);
    swap(nums[startIdx], nums[i]);
  }
}

vector<vector<int>> permute(vector<int> &nums) {

  getPermutation(nums, 0);

  return res;
}

int main() {

  vector<int> nums = {1, 2, 3};
  vector<vector<int>> v = permute(nums);

  print_vector(v);

  return 0;
}
