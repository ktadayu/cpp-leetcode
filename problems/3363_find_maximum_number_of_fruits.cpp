#include "common.hpp"
using ll = long long;

int maxCollectedFruits(vector<vector<int>> &fruits) {
  int n = fruits.size();
  int sum_a = 0;

  for (size_t i = 0; i < n; ++i) {
    sum_a += fruits[i][i];
    if (i < n - 1)
      fruits[i][i] = -1;
  }
  vector<ll> dp_b(n, -1);
  if (fruits[0][n - 1] != -1)
    dp_b[n - 1] = fruits[0][n - 1];
  for (int i = 1; i < n; ++i) {
    ll old_left = -1;
    for (int j = 0; j < n; ++j) {
      ll old_mid = dp_b[j];
      ll old_right = (j + 1 < n ? dp_b[j + 1] : -1);
      ll best = -1;
      if (old_left != -1)
        best = max(best, old_left);
      if (old_mid != -1)
        best = max(best, old_mid);
      if (old_right != -1)
        best = max(best, old_right);
      ll next = -1;
      if (fruits[i][j] != -1 && best != -1)
        next = best + fruits[i][j];
      old_left = old_mid;
      dp_b[j] = next;
    }
  }
  ll bestB = dp_b[n - 1];

  vector<ll> dp_c(n, -1);
  if (fruits[n - 1][0] != -1)
    dp_c[n - 1] = fruits[n - 1][0];
  for (int j = 1; j < n; ++j) {
    ll old_up = -1;
    for (int i = 0; i < n; ++i) {
      ll old_mid = dp_c[i];
      ll old_down = (i + 1 < n ? dp_c[i + 1] : -1);
      ll best = -1;
      if (old_up != -1)
        best = max(best, old_up);
      if (old_mid != -1)
        best = max(best, old_mid);
      if (old_down != -1)
        best = max(best, old_down);
      ll next = -1;
      if (fruits[i][j] != -1 && best != -1)
        next = best + fruits[i][j];
      old_up = old_mid;
      dp_c[i] = next;
    }
  }
  ll bestC = dp_c[n - 1];

  ll ans = sumA + bestB + bestC - goal;
  return ans;
}

int main() { return 0; }
