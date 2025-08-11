#include "common.hpp"
int maxArea(vector<int> &height) {
  int n = height.size();
  int curr = 0;
  for (int l = 0, r = n - 1; l < r;) {
    int h_l = height[l];
    int h_r = height[r];
    int area = (r - l) * min(h_l, h_r);
    curr = max(curr, area);
    if (h_l <= h_r) {
      ++l;
      // ここに自明なl飛ばすskip処理入れると速いよ
      continue;
    }
    if (h_r < h_l) {
      --r;
      continue;
    }
  }
  return curr;
}

int main() {
  // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height = {1, 1};
  int k = maxArea(height);

  cout << k << endl;

  return 0;
}
