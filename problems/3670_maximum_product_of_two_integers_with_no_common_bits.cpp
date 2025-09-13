#include "common.hpp"
using namespace std;

long long maxProduct(vector<int> &nums) {

  int mx = *max_element(nums.begin(), nums.end());
  int k = __builtin_clz(mx);
  int bit_length = 32 - k;
  int bit_mask = (1 << bit_length) - 1;

  vector<int> dp(bit_mask + 1, 0);
  for (int i : nums) {
    dp[i] = i;
  }

  int n = nums.size();
  for (int i = 0; i < bit_length; ++i) {
    for (int j = 0; j <= bit_mask; ++j) {
      if (j & (1 << i)) {
        dp[j] = max(dp[j], dp[j ^ (1 << i)]);
      }
    }
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, (long long)nums[i] * (long long)dp[(~nums[i]) & bit_mask]);
  }

  return res;
}

int main() {

  // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  //  vector<int> nums = {1, 2, 5, 7};
  // long long k = maxProduct(nums);
  int x = 8;         // 1000
  int bit_mask = 15; // 1111
  cout << ((~x) & bit_mask) << endl;

  return 0;
}
