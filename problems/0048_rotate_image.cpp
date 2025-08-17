#include "common.hpp"
// 標準ライブラリを使った方が速いらしい
void reverse_row(vector<int> &v) {
  for (size_t i = 0; i < v.size() / 2; i++) {
    swap(v[i], v[v.size() - i - 1]);
  }
}

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    std::reverse(matrix.begin(), matrix.end());
  }
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  reverse_row(v);
  print_vector(v);

  return 0;
}
