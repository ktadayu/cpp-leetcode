#include "common.hpp"

double new21Game(int n, int k, int maxPts) {
  if (k == 0) {
    return 1;
  }
  vector<double> dp(n + 1, 0.0);
  dp[0] = 1.0;
  double sum = 1.0;
  double ans = 0.0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = sum / maxPts;
    if (i < k) {
      sum += dp[i];
    } else {
      ans += dp[i];
    }
    if (0 <= i - maxPts) {
      sum -= dp[i - maxPts];
    }
  }
  return ans;
}

int main() {
  int n = 21;
  int k = 17;
  int maxPts = 10;

  double res = new21Game(n, k, maxPts);

  cout << res << endl;

  return 0;
}
