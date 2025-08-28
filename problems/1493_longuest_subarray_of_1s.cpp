#include "common.hpp"
// スライディングウインドウのが絶対良い
int longestSubarray(vector<int> &nums) {
  int n = nums.size();
  vector<int> tmp(n, 0);
  int curr = 0;
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      tmp[i] = curr;
      curr = 0;
    } else {
      f = 1;
      curr++;
    }
  }
  print_vector(tmp);
  curr = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[n - i - 1] == 0) {
      tmp[n - i - 1] += curr;
      curr = 0;
    } else {
      curr++;
    }
  }
  print_vector(tmp);
  int mx = *max_element(tmp.begin(), tmp.end());
  if (flag == 0) {
    return 0;
  }
  if (mx == 0) {
    return n - 1;
  }

  return mx;
}

int main() {
  // vector<int> v = {0, 1, 1, 1, 0, 1, 1, 0};

  vector<int> v = {1, 1, 1, 1, 1, 1};
  int k = longestSubarray(v);
  cout << k << endl;
  return 0;
}
