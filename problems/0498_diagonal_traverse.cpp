#include "common.hpp"

vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
  int m = mat.size();
  int n = mat[0].size();

  bool up_mode = true;
  vector<int> res;
  res.reserve(m * n);
  int r = 0, c = 0;
  for (int i = 0; i < m * n; ++i) {
    res.push_back(mat[r][c]);
    if (up_mode) {
      --r;
      ++c;
    } else {
      ++r;
      --c;
    }

    if (r < 0 && c > n - 1) {
      r += 2;
      --c;
      up_mode = !up_mode;
      continue;
    }
    if (r < 0 && c < n) {
      ++r;
      up_mode = !up_mode;
      continue;
    }

    if (r > m - 1 && c < 0) {
      --r;
      c += 2;
      up_mode = !up_mode;
      continue;
    }
    if (r > m - 1 && c >= 0) {
      --r;
      c += 2;
      up_mode = !up_mode;
      continue;
    }
    if (c < 0) {
      ++c;
      up_mode = !up_mode;
      continue;
    }
    if (c > n - 1) {
      cout << "r:" << r << endl;
      cout << "c" << c << endl;
      --c;
      r += 2;
      up_mode = !up_mode;
      continue;
    }
  }
  return res;
}

int main() {

  // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // vector<vector<int>> mat = {{1, 2}, {3, 4}};

  vector<vector<int>> mat = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<int> v = findDiagonalOrder(mat);
  print_vector(v);

  return 0;
}
