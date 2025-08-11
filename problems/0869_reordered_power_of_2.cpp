#include "common.hpp"

array<int, 10> count(int n) {
  array<int, 10> cnt{};
  cnt.fill(0);
  while (n > 0) {
    cnt[n % 10]++;
    n /= 10;
  }
  return cnt;
}

bool reorderedPowerOf2(int n) {
  string itos = to_string(n);
  int keta = itos.size();

  //  vector<int> p2list;
  auto target = count(n);
  for (int x = 1;; x <<= 1) {
    int l = to_string(x).size();
    if (l > keta) {
      break;
    }
    if (l == keta) {
      if (count(x) == target) {
        return true;
      }
      //     p2list.push_back((int)x);
    }
  }

  return false;
}
int main() {
  int n = 16;
  bool res = reorderedPowerOf2(n);
  cout << res << endl;
  return 0;
}
