#include "common.hpp"
int kthGrammar(int n, int k) {
  if (n == 1) {
    return 0;
  }
  if (k & 1) {
    return kthGrammar(n - 1, (k + 1) / 2);
  }
  return 1 ^ kthGrammar(n - 1, (k + 1) / 2);
}
int main() {
  int n = 2;
  int k = 1;
  int res = kthGrammar(n, k);

  cout << res << endl;

  return 0;
}
