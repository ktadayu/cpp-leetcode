#include "common.hpp"

vector<int> productQueries(int n, vector<vector<int>> &queries) {

  vector<int> powers;
  int bl = 0;
  while (n > 0) {
    if (n & 1) {
      powers.push_back(1 << bl);
    }
    n >>= 1;
    ++bl;
  }

  vector<int> res;
  int MOD = 1e9 + 7;
  for (auto &q : queries) {
    int i = q[0];
    int r = q[1];
    int tmp = 1;
    for (int j = i; j < r + 1; j++) {
      tmp = (tmp * powers[j]) % MOD;
    }
    res.push_back(tmp);
  }

  return res;
}

int main() {
  int n = 2;
  // vector<vector<int>> queries = {{0, 1}, {2, 2}, {0, 3}};
  vector<vector<int>> queries = {{0, 0}};
  vector<int> v = productQueries(n, queries);
  print_vector(v);

  return 0;
}
