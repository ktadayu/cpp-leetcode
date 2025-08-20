#include "common.hpp"
#include <numeric>

struct UnionFindTree {
  vector<int> p, rk;
  UnionFindTree(int n = 0) { init(n); }
  void init(int n) {
    p.resize(n);
    rk.assign(n, 0);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    if (p[x] == x) {
      return x;
    }
    return p[x] = find(p[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return;
    }
    if (rk[a] < rk[b]) {
      swap(a, b);
    }
    p[b] = a;
    if (rk[a] == rk[b]) {
      rk[a]++;
    }
  }
  bool same(int a, int b) { return find(a) == find(b); }
};

inline int idx(int r, int c, int ncols) { return r * ncols + c; }

void solve(vector<vector<char>> &board) {
  int m = board.size();
  int n = board[0].size();

  UnionFindTree uft(m * n + 1);

  int dummy = m * n;
  auto isEdge = [&](int r, int c) {
    return r == 0 || c == 0 || r == m - 1 || c == n - 1;
  };

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] != 'O') {
        continue;
      }
      if (isEdge(r, c)) {
        uft.unite(idx(r, c, n), dummy);
      }
    }
  }
  int dr[2] = {0, 1};
  int dc[2] = {1, 0};
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] != 'O') {
        continue;
      }
      int a = idx(r, c, n);
      for (int k = 0; k < 2; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < m && nc < n && board[nr][nc] == 'O') {
          int b = idx(nr, nc, n);
          uft.unite(a, b);
        }
      }
    }
  }

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] != 'O') {
        continue;
      }
      if (!uft.same(idx(r, c, n), dummy)) {
        board[r][c] = 'X';
      }
    }
  }
}

int main() {
  UnionFindTree dft(5);
  dft.unite(0, 1);
  dft.unite(2, 3);
  dft.unite(0, 3);

  cout << dft.same(0, 2) << endl;
  cout << dft.same(0, 3) << endl;
  return 0;
}
