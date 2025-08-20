#include "common.hpp"

vector<int> twoSum(vector<int> &numbers, int target) {
  int n = numbers.size();
  for (int l = 0, r = 1; l < r; ++l) {
    cout << "l:" << l << endl;
    int t = target - numbers[l];
    cout << "t:" << t << endl;
    while (r < n) {
      cout << "r:" << r << endl;
      if (numbers[r] == t) {
        return vector<int>{l + 1, r + 1};
      }
      if (numbers[r] > t) {
        break;
      }
      r++;
    }
    cout << "---------------" << endl;
  }

  return {0, 0};
}

int main() {
  vector<int> v = {1, 2, 3, 4, 7, 22, 35};
  int target = 42;
  vector<int> res = twoSum(v, target);
  print_vector(res);
  return 0;
}
