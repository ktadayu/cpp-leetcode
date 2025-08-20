#include "common.hpp"

int countSquares(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  vector<int> dp(n, 0);
  int res = 0;

  for (int i = 0; i < m; ++i) {
    int diag = 0;
    for (int j = 0; j < n; ++j) {
      int up = dp[j];
      if (matrix[i][j]) {
        int left = 0;
        if (j != 0) {
          left = dp[j - 1];
        }
        dp[j] = min({left, up, diag}) + 1;
        res += dp[j];
      } else {
        dp[j] = 0;
      }
      diag = up;
    }
  }
  return res;
}

int main() { return 0; }
