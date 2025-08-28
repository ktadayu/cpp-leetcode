#include "common.hpp"
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
  int n = grid.size();

  for (int i = 1; i < n; ++i) {
    // start (0,i) end (0,n-1)
    vector<int> tmp;
    tmp.reserve(i);
    for (int j = 0; j + i < n; ++j) {
      tmp.push_back(grid[j][i + j]);
    }
    sort(tmp.begin(), tmp.end());
    for (int j = 0; i + j < n; ++j) {
      grid[j][i + j] = tmp[j];
    }
  }

  for (int i = 0; i < n; ++i) {
    // start (0,0) end (n-1,0)
    vector<int> tmp;
    tmp.reserve(i + 1);
    for (int j = 0; i + j < n; ++j) {
      tmp.push_back(grid[i + j][j]);
    }
    sort(tmp.rbegin(), tmp.rend());
    for (int j = 0; j + i < n; ++j) {
      grid[i + j][j] = tmp[j];
    }
  }
  return grid;
}

int main() {
  vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
  vector<vector<int>> res = sortMatrix(grid);
  print_vector(res);

  vector<vector<int>> grid2 = {{0, 1}, {1, 2}};
  vector<vector<int>> res2 = sortMatrix(grid2);
  print_vector(res2);

  return 0;
}
