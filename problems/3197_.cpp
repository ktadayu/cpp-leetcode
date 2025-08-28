#include "common.hpp"

long long getArea(int r1, int c1, int r2, int c2, vector<pair<int, int>> &v) {
  int mn_r = INT_MAX, mx_r = INT_MIN;
  int mn_c = INT_MAX, mx_c = INT_MIN;
  bool found = false;
  for (auto &p : v) {
    int r = p.first;
    int c = p.second;
    if (r >= r1 && r <= r2 && c >= c1 && c <= c2) {
      found = true;
      mn_r = min(mn_r, r);
      mx_r = max(mx_r, r);
      mn_c = min(mn_c, c);
      mx_c = max(mx_c, c);
    }
  }
  if (!found) {
    return 0;
  }
  return (mx_r - mn_r + 1) * (mx_c - mn_c + 1);
}

int minimumSum(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  vector<pair<int, int>> v;
  v.reserve(m * n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        v.push_back({i, j});
      }
    }
  }
  long long min_total = LLONG_MAX;

  for (int y1 = 0; y1 < m - 1; ++y1) {
    for (int y2 = y1 + 1; y2 < m - 1; ++y2) {
      long long a1 = getArea(0, 0, y1, n - 1, v);
      long long a2 = getArea(y1 + 1, 0, y2, n - 1, v);
      long long a3 = getArea(y2 + 1, 0, m - 1, n - 1, v);
      if (a1 > 0 && a2 > 0 && a3 > 0) {
        min_total = min(min_total, a1 + a2 + a3);
      }
    }
  }

  for (int x1 = 0; x1 < n - 1; ++x1) {
    for (int x2 = x1 + 1; x2 < n - 1; ++x2) {
      long long a1 = getArea(0, 0, m - 1, x1, v);
      long long a2 = getArea(0, x1 + 1, m - 1, x2, v);
      long long a3 = getArea(0, x2 + 1, m - 1, n - 1, v);
      if (a1 > 0 && a2 > 0 && a3 > 0) {
        min_total = min(min_total, a1 + a2 + a3);
      }
    }
  }

  for (int i = 0; i < m - 1; ++i) {   // 水平
    for (int j = 0; j < n - 1; ++j) { // 垂直
      // p1
      long long a1 = getArea(0, 0, i, n - 1, v);
      long long a2 = getArea(i + 1, 0, m - 1, j, v);
      long long a3 = getArea(i + 1, j + 1, m - 1, n - 1, v);
      if (a1 > 0 && a2 > 0 && a3 > 0)
        min_total = min(min_total, a1 + a2 + a3);

      // p2
      a1 = getArea(i + 1, 0, m - 1, n - 1, v);
      a2 = getArea(0, 0, i, j, v);
      a3 = getArea(0, j + 1, i, n - 1, v);
      if (a1 > 0 && a2 > 0 && a3 > 0)
        min_total = min(min_total, a1 + a2 + a3);
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      // p3
      long long a1 = getArea(0, 0, m - 1, i, v);
      long long a2 = getArea(0, i + 1, j, n - 1, v);
      long long a3 = getArea(j + 1, i + 1, m - 1, n - 1, v);
      if (a1 > 0 && a2 > 0 && a3 > 0)
        min_total = min(min_total, a1 + a2 + a3);

      // p4
      a1 = getArea(0, i + 1, m - 1, n - 1, v);
      a2 = getArea(0, 0, j, i, v);
      if (a1 > 0 && a2 > 0 && a3 > 0)
        min_total = min(min_total, a1 + a2 + a3);
      a3 = getArea(j + 1, 0, m - 1, i, v);
    }
  }
  return min_total;
}
int main() { return 0; }
