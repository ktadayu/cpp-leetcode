#include "common.hpp"

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  int top = 0, right = n - 1, bottom = m - 1, left = 0;
  vector<int> res;
  res.reserve(m * n);
  while (top <= bottom && left < right) {
    for (int i = left; i <= right; ++i) {
      cout << "left to right:" << i << endl;
      res.push_back(matrix[top][i]);
    }
    ++top;
    for (int i = top; i <= bottom; ++i) {
      cout << "top to bottom:" << i << endl;
      res.push_back(matrix[i][right]);
    }
    --right;
    if (top <= bottom) {
      for (int i = right; left <= i; --i) {
        cout << "right to left:" << i << endl;
        res.push_back(matrix[bottom][i]);
      }
      --bottom;
      for (int i = bottom; top <= i; --i) {
        cout << "bottom to top:" << i << endl;
        res.push_back(matrix[i][left]);
      }
      ++left;
    }
  }
  return res;
}

int main() {

  // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  vector<int> res = spiralOrder(matrix);
  print_vector(res);

  return 0;
}
