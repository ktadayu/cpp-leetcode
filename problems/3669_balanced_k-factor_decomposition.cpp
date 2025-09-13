#include "common.hpp"

int curr_mx = INT_MAX;
vector<int> res;

void dfs(int n, int k, vector<int> curr, int start) {
  if (k == 1) {
    curr.push_back(n);
    int mn = *min_element(curr.begin(), curr.end());
    int mx = *max_element(curr.begin(), curr.end());
    if (mx - mn < curr_mx) {
      curr_mx = mx - mn;
      res = curr;
    }
    curr.pop_back();
    return;
  }

  for (int i = start; i < n + 1; ++i) {
    if (n % i == 0) {
      curr.push_back(i);
      dfs(n / i, k - 1, curr, i);
      curr.pop_back();
    }
  }
}

vector<int> minDifference(int n, int k) {
  vector<int> curr;
  dfs(n, k, curr, 1);
  return res;
}

int main() {
  int n = 1000;
  int k = 4;
  vector<int> v = minDifference(n, k);
  print_vector(v);

  return 0;
}
