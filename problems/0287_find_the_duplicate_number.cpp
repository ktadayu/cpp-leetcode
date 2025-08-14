#include "common.hpp"

int findDuplicate(vector<int> &nums) {
  int p1 = 0;
  int p2 = 0;
  while (true) {
    p2 = nums[p2];
    p2 = nums[p2];
    p1 = nums[p1];

    if (p1 == p2) {
      int q1 = p1;
      int q2 = 0;
      while (q1 != q2) {
        q1 = nums[q1];
        q2 = nums[q2];
      }
      return q1;
    }
  }
  return 0;
}

int main() {
  vector<int> nums = {2, 3, 1, 4, 4};
  int k = findDuplicate(nums);
  cout << k << endl;

  return 0;
}
