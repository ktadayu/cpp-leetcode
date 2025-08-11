#include "common.hpp"

int maxProduct(vector<int> &nums) {

  int currMx = 0;
  int currMn = 0;
  int res = 0;
  bool isFirst = true;
  for (int &i : nums) {
    if (isFirst) {
      currMx = currMn = res = i;
      isFirst = false;
      continue;
    }
    if (i < 0) {
      swap(currMx, currMn);
    }
    currMx = max(i, currMx * i);
    currMn = min(i, currMn * i);
    res = max(res, currMx);
  }
  return res;
}

int main() {
  vector<int> nums = {2, 3, 0, -2, 4, -2};
  // vector<int> nums = {-1, 4, -2, 4, 5, 6, -1};
  int k = maxProduct(nums);
  cout << k << endl;

  return 0;
}
