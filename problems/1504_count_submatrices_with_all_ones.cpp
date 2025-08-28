#include "common.hpp"
int numSubmat(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  vector<vector<int>> dph(m, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    dph[0][i] = matrix[0][i];
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 1) {
        dph[i][j] = dph[i - 1][j] + 1;
      }
    }
    int sum = 0;
    stack<pair<int, int>> st;

    for (int j = 0; j < n; ++j) {
      int w = 1;
      int h = dph[j];
      while (!st.empty() && h <= st.top().fitst) {
        auto [h2, w2] = st.top();
        st.pop();
        sum -= (h2 - h) * w2;
        w += w2;
      }
      st.push({h, width});
      sum += h * w;
      res += sum;
    }
  }

  int res;

  return dph;
}
int main() {
  vector<vector<int>> matrix = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
  auto res = numSubmat(matrix);
  print_vector(res);

  return 0;
}
