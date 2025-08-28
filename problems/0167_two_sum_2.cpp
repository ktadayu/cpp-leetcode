#include "common.hpp"

vector<int> twoSum(vector<int> &numbers, int target) {
  int n = numbers.size();
  int l = 0;
  int r = n - 1;

  while (l < r) {
    int t = numbers[l] + numbers[r];
    if (t == target) {
      return {l + 1, r + 1};
    }
    if (t < target) {
      ++l;
      continue;
    }
    --r;
  }

  return {0, 0};
}

int main() {
  // vector<int> v = {1, 2, 3, 4, 7, 22, 35, 37};
  vector<int> v = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = twoSum(v, target);
  print_vector(res);
  return 0;
}
