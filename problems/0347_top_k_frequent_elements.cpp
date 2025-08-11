#include "common.hpp"
using Pair = pair<int, int>;
using Mh = priority_queue<Pair, vector<Pair>, greater<Pair>>;

vector<int> topKFrequent(vector<int> &nums, int k) {
  vector<int> ans(k, 0);
  int n = nums.size();
  unordered_map<int, int> um;

  for (int i : nums) {
    ++um[i];
  }

  Mh mh;
  for (auto &[num, freq] : um) {
    mh.push({freq, num});
    if (mh.size() > k) {
      mh.pop();
    }
  }
  int i = 0;
  while (!mh.empty() & i < k) {
    ans[i] = mh.top().second;
    mh.pop();
    ++i;
  }

  return ans;
}

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  vector<int> ans = topKFrequent(nums, 2);
  print_vector(ans);
  return 0;
}
