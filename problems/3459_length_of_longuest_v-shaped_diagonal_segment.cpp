#include "common.hpp"

int lenOfVDiagonal(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int mx = 0;

  // using Mat = vector<vector<int>> ;
  auto makeMat = [](int n, int m) {
    return vector<vector<int>>(n, vector<int>(m, 0));
  };

  // 右上
  auto ru0 = makeMat(n, m);
  auto ru2 = makeMat(n, m);
  auto lru = makeMat(n, m);
  // 右下
  auto rd0 = makeMat(n, m);
  auto rd2 = makeMat(n, m);
  auto lrd = makeMat(n, m);
  // 左上
  auto lu0 = makeMat(n, m);
  auto lu2 = makeMat(n, m);
  auto llu = makeMat(n, m);
  // 左下
  auto ld0 = makeMat(n, m);
  auto ld2 = makeMat(n, m);
  auto lld = makeMat(n, m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 || j == 0) {
        lu0[i][j] = (grid[i][j] == 0 ? 1 : 0);
        lu2[i][j] = (grid[i][j] == 2 ? 1 : 0);
        continue;
      }
      if (grid[i][j] == 0)
        lu0[i][j] = 1 + lu2[i - 1][j - 1];
      if (grid[i][j] == 2)
        lu2[i][j] = 1 + lu0[i - 1][j - 1];
    }

    for (int j = m - 1; j >= 0; --j) {
      if (i == 0 || j == m - 1) {
        ru0[i][j] = (grid[i][j] == 0 ? 1 : 0);
        ru2[i][j] = (grid[i][j] == 2 ? 1 : 0);
        continue;
      }
      if (grid[i][j] == 0)
        ru0[i][j] = 1 + ru2[i - 1][j + 1];
      if (grid[i][j] == 2)
        ru2[i][j] = 1 + ru0[i - 1][j + 1];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      if (i == n - 1 || j == 0) {
        ld0[i][j] = (grid[i][j] == 0 ? 1 : 0);
        ld2[i][j] = (grid[i][j] == 2 ? 1 : 0);
        continue;
      }
      if (grid[i][j] == 0)
        ld0[i][j] = 1 + ld2[i + 1][j - 1];
      if (grid[i][j] == 2)
        ld2[i][j] = 1 + ld0[i + 1][j - 1];
    }

    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 || j == m - 1) {
        rd0[i][j] = (grid[i][j] == 0 ? 1 : 0);
        rd2[i][j] = (grid[i][j] == 2 ? 1 : 0);
        continue;
      }
      if (grid[i][j] == 0)
        rd0[i][j] = 1 + rd2[i + 1][j + 1];
      if (grid[i][j] == 2)
        rd2[i][j] = 1 + rd0[i + 1][j + 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1) {
        llu[i][j] = 1 + (i > 0 && j > 0 ? lu2[i - 1][j - 1] : 0);
        lru[i][j] = 1 + (i > 0 && j < m - 1 ? ru2[i - 1][j + 1] : 0);
        lld[i][j] = 1 + (i < n - 1 && j > 0 ? ld2[i + 1][j - 1] : 0);
        lrd[i][j] = 1 + (i < n - 1 && j < m - 1 ? rd2[i + 1][j + 1] : 0);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mx = max({mx, llu[i][j], lru[i][j], lld[i][j], lrd[i][j]});

      if (grid[i][j] == 1) {
        if (lru[i][j] > 0 && lrd[i][j] > 0)
          mx = max(mx, lru[i][j] + lrd[i][j] - 1);
        if (lrd[i][j] > 0 && lld[i][j] > 0)
          mx = max(mx, lrd[i][j] + lld[i][j] - 1);
        if (lld[i][j] > 0 && llu[i][j] > 0)
          mx = max(mx, lld[i][j] + llu[i][j] - 1);
        if (llu[i][j] > 0 && lru[i][j] > 0)
          mx = max(mx, llu[i][j] + lru[i][j] - 1);
      }
    }
  }
  return mx;
}

int main() {
  vector<vector<int>> grid2 = {{0, 1, 0}, {1, 2, 1}, {0, 1, 0}};
  cout << "Grid 2 の最長V字長: " << lenOfVDiagonal(grid2) << endl;

  return 0;
}
