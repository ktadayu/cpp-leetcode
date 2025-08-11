#include "common.hpp"
#include <tuple>
using namespace std;

using Tpl = tuple<int, int, int>;
using Pq = priority_queue<Tpl, vector<Tpl>, greater<Tpl>>;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                   int k) {
  int n = nums1.size();
  vector<vector<int>> ans;
  Pq pq;
  for (int i = 0; i < n; ++i) {
    pq.push({nums1[i] + nums2[0], i, 0});
  }

  while (!pq.empty() && ans.size() != k) {
    auto [sum, i, j] = pq.top();
    pq.pop();

    ans.push_back(vector<int>{nums1[i], nums2[j]});
    if (j + 1 < nums2.size()) {
      pq.push({nums1[i] + nums2[j + 1], i, j + 1});
    }
  }
  return ans;
}

int main() {
  vector<int> nums1 = {1, 1, 2};
  vector<int> nums2 = {1, 2, 3};
  vector<vector<int>> ans = kSmallestPairs(nums1, nums2, 3);
  print_vector(ans);
  return 0;
}
