#include "common.hpp"
int totalFruit(vector<int> &fruits) {
  int n = fruits.size();
  if (n <= 2) {
    return n;
  }
  // type2は最も右側にあるフルーツの種類
  int type1 = fruits[0], type2 = fruits[1];
  // last_fの連続長
  int last_c = type1 == type2 ? 2 : 1;
  int curr_l = 2;
  int res = 2;
  int l = 0;
  for (int r = 2; r < n; ++r) {
    if (type1 == type2 && fruits[r] != type1) {
      type2 = fruits[r];
      last_c = 1;
      curr_l = r - l + 1;
      res = max(curr_l, res);
      continue;
    }
    if (fruits[r] != type1 && fruits[r] != type2) {
      l = r - last_c;
      curr_l = r - l + 1;
      res = max(curr_l, res);
      type1 = type2;
      type2 = fruits[r];
      last_c = 1;
      continue;
    }
    if (fruits[r] == type1) {
      ++curr_l;
      res = max(curr_l, res);
      swap(type1, type2);
      last_c = 1;
      continue;
    }
    if (fruits[r] == type2) {
      ++curr_l;
      res = max(curr_l, res);
      ++last_c;
    }
  }

  return res;
}
int main() {
  vector<int> fruits = {3, 3, 3, 1, 4};
  int k = totalFruit(fruits);

  cout << "答え:" << k << endl;

  return 0;
}
