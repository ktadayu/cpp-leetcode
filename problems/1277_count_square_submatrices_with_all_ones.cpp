#include "common.hpp"

int countSquares(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  auto isBoundary = [&](int r, c) { return r == 0 || c == 0; };

  vector<vector<int>> dp(m, vector<int>(n, 0));
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isBoundary(i, j)) {
        dp[i][j] = matrix[i][j];
        cnt += matrix[i][j];
        continue;
      }
      if (matrix[i][j] == 1) {
        dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
        cnt += dp[i][j];
      }
    }
  }
  return cnt;
};

int main() { return 0; }
