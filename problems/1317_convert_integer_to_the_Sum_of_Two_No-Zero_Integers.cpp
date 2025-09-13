#include "common.hpp"

bool check(int n) {
  if (n == 0) {
    return false;
  }
  bool res = true;
  while (n > 0) {
    int r = n % 10;
    if (r == 0) {
      return false;
    }
    n = n / 10;
  }
  return res;
}

vector<int> getNoZeroIngegers(int n) {

  for (int i = 1; i <= n / 2; ++i) {
    int a = i;
    int b = n - i;
    bool res1 = check(a);
    bool res2 = check(b);
    if (res1 && res2) {
      return {a, b};
    }
  }

  return {};
}

int main() {

  for (int i = 101; i <= 1000; ++i) {
    int n = i;
    vector<int> ans = getNoZeroIngegers(n);
    print_vector(ans);
  }

  return 0;
}
