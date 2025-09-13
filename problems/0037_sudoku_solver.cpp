#include "common.hpp"
using namespace std;

int boxId(int r, int c) { return (r - r % 3) + (c / 3); }

static constexpr uint16_t _1to9 = 0x3FE;
array<uint16_t, 9> rows{}, clus{}, boxes{};

bool dfs(vector<vector<char>> &board) {
  int bestR = -1, bestC = -1;
  uint16_t bestCand = 0;
  int bestCnt = 10;

  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      if (board[r][c] != '.') {
        continue;
      }
      int bId = boxId(r, c);
      uint16_t used = rows[r] | clus[c] | boxes[bId];
      uint16_t cand = _1to9 & ~used;
      int cnt = __builtin_popcount((unsigned)cand);
      if (cnt < bestCnt) {
        bestCnt = cnt;
        bestR = r;
        bestC = c;
        bestCand = cand;
      }
    }
  }
  if (bestR == -1) {
    return true;
  }
  if (bestCnt == 0) {
    return false;
  }

  int r = bestR, c = bestC, bId = boxId(r, c);
  uint16_t cand = bestCand;

  while (cand) {
    uint16_t one = cand & -cand;
    int d = __builtin_ctz((unsigned)one);
    uint16_t bit = uint16_t(1u << d);

    rows[r] |= bit;
    clus[c] |= bit;
    boxes[bId] |= bit;
    board[r][c] = char(d + '0');

    if (dfs(board)) {
      return true;
    }
    rows[r] &= ~bit;
    clus[c] &= ~bit;
    boxes[bId] &= ~bit;
    board[r][c] = '.';

    cand ^= one;
  }
  return false;
}

void solveSudoku(vector<vector<char>> &board) {
  for (int r = 0; r < 9; ++r) {
    for (int c = 0; c < 9; ++c) {
      if (board[r][c] == '.') {
        continue;
      }
      int d = board[r][c] - '0';
      uint16_t bit = uint16_t(1u << d);
      rows[r] |= bit;
      clus[c] |= bit;
      boxes[boxId(r, c)] |= bit;
    }
  }
  dfs(board);
}

int main() { return 0; }
