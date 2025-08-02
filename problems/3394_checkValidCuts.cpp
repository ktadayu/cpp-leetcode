#include "common.hpp"

bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
  sort(rectangles.begin(), rectangles.end(),
       [](auto &a, auto &b) { return a[0] < b[0]; });

  int m = rectangles.size();
  int group_1 = 1;
  bool res_1 = false;
  int currEnd = rectangles[0][2];
  for (int i = 1; i < m; ++i) {
    if (rectangles[i][0] >= currEnd) {
      ++group_1;
      currEnd = rectangles[i][2];
    } else {
      currEnd = max(currEnd, rectangles[i][2]);
    }
  }

  if (group_1 >= 3) {
    res_1 = true;
  }
  sort(rectangles.begin(), rectangles.end(),
       [](auto &a, auto &b) { return a[1] < b[1]; });

  int group_2 = 1;
  bool res_2 = false;
  int currEnd_2 = rectangles[0][3];
  for (int i = 1; i < m; ++i) {
    if (rectangles[i][1] >= currEnd_2) {
      ++group_2;
      currEnd_2 = rectangles[i][3];
    } else {
      currEnd_2 = max(currEnd_2, rectangles[i][3]);
    }
  }
  if (group_2 >= 3) {
    res_2 = true;
  }

  return res_1 || res_2;
}

int main() {
  vector<vector<int>> rec = {
      {0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};

  // { {1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
  bool res = checkValidCuts(4, rec);

  cout << res << endl;
  return 0;
}
