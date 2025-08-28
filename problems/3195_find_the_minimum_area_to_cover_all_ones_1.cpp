#include "common.hpp"

int minimumArea(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int left = n - 1, right = 0;
  int top = m - 1, bottom = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        right = max(right, j);
        left = min(left, j);
        top = min(top, i);
        bottom = max(bottom, i);
      }
    }
  }
  cout << left << endl;
  cout << right << endl;
  cout << top << endl;
  cout << bottom << endl;
  if (left > right) {
    return 0;
  }
  return (right - left + 1) * (bottom - top + 1);
}

int main() {
  vector<vector<int>> grid = {{1, 0}, {0, 0}};
  int k = minimumArea(grid);
  cout << k << endl;
  return 0;
}
