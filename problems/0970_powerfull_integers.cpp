#include "common.hpp"

vector<int> powerfulIntegers(int x, int y, int bound) {
  unordered_set<int> us;
  int tmp_x = 1;
  while (tmp_x <= bound) {
    int tmp_y = 1;
    while (tmp_x + tmp_y <= bound) {
      us.insert(tmp_x + tmp_y);
      if (y == 1) {
        break;
      }
      tmp_y = tmp_y * y;
    }
    if (x == 1) {
      break;
    }
    tmp_x = tmp_x * x;
  }
  return vector<int>(us.begin(), us.end());
}
int main() {
  int x = 2;
  int y = 3;
  int bound = 10;
  vector<int> v = powerfulIntegers(x, y, bound);
  print_vector(v);

  return 0;
}
