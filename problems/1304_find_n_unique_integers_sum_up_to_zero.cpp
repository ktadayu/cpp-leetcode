#include "common.hpp"

vector<int> sumZero(int n) {
  if (n <= 0) {
    return {};
  }
  if (n == 2) {
    return {-1, 1};
  }
  vector<int> res;
  res.reserve(n);
  int curr = 0;
  for (int i = 0; i < n - 1; ++i) {
    res.push_back(i);
    curr += i;
  }
  res.push_back(-curr);
  return res;
}

int main() {
  int n = 2;
  vector<int> v = sumZero(n);
  print_vector(v);

  return 0;
}
