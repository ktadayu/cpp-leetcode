
#include "common.hpp"
int check(vector<int> nums) {
  int n = nums.size();
  int curr_mx = 0;
  int l = nums[0], r = nums[n - 1];
  for (int i = 1; i < n - 1; ++i) {
    if (l <= nums[i]) {
      return -1;
    }
    curr_mx = max(curr_mx, nums[i]);
  }
  int mn_edge = min(l, r);
  if (curr_mx < mn_edge) {
    return 2;
  } else if (curr_mx < r) {
    return 1;
  }
  return 0;
}

long long bowlSubarrays(vector<int> &nums) {
  int n = nums.size();
  long long res = 0;
  for (int start = 0; start <= n - 3; start++) {
    int len = 2;
    bool canExtend = true;
    while (start + len + 1 <= n && canExtend) {
      vector<int> q(nums.begin() + start, nums.begin() + start + len + 1);
      int k = check(q);
      if (k == 0) {
        if (q[0] <= *max_element(q.begin() + 1, q.end() - 1)) {
          canExtend = false;
        }
      } else if (k == 2) {
        res++;
      }
      len++;
    }
  }
  return res;
}
int main() {
  vector<int> v = {2, 5, 3, 1, 4};
  long long l = bowlSubarrays(v);
  cout << l << endl;
  return 0;
}
