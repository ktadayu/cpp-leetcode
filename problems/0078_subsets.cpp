#include "common.hpp"

// subsetのk番目の要素についての選択
void addSubsets(vector<vector<int>> &v, vector<int> nums, int k) {
  if (k >= (int)nums.size()) {
    return;
  }
  // 取らない
  // addSubsets(v, nums, k + 1);
  //  取る
  //  for (auto u : v) {
  //    vector<int> tmp = u;
  //    tmp.push_back(nums[k]);
  //    v.push_back(tmp);
  //  }

  size_t m = v.size();
  for (size_t i = 0; i < m; ++i) {
    auto tmp = v[i];
    tmp.push_back(nums[k]);
    v.push_back(move(tmp));
  }
  addSubsets(v, nums, k + 1);
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> res;
  int n = nums.size();
  res.reserve(1 << n);
  res.push_back(vector<int>{});
  addSubsets(res, nums, 0);
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = subsets(nums);
  print_vector(res);

  return 0;
}
