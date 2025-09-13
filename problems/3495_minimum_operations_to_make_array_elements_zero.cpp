#include "common.hpp"
long long totalRound(long long n) {
  if (n <= 0) {
    return 0;
  }
  long long rounds = 0;

  long long block_left = 1;
  long long rounds_cnt = 1;

  while (block_left <= n) {
    long long block_right = block_left * 4 - 1;

    long long segL = block_left;
    long long segR = min(block_right, n);

    if (segL <= segR) {
      long long count = segR - segL + 1;
      rounds += count * rounds_cnt;
    }

    block_left *= 4;
    rounds_cnt++;
  }

  return total_rounds;
}

long long minOperations(vector<vector<int>> &queries) {
  long long ans = 0;
  for (auto &q : queries) {
    long long l = q[0], r = q[1];
    long long T = totalRound(r) - totalRound(l - 1);
    ans += (T + 1) / 2;
  }
  return ans;
}

int main() { return 0; }
