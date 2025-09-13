#include "common.hpp"

int minOperations(string s) {
  vector<int> alphaCnt(26, 0);
  for (char &c : s) {
    alphaCnt[c - 'a']++;
  }
  print_vector(alphaCnt);
  int res = 0;
  for (int i = 0; i < 26; ++i) {
    if (i == 0) {
      continue;
    }
    if (alphaCnt[i] != 0) {
      return 26 - i;
    }
  }
  return res;
}

int main() {
  string s = "yz";
  int k = minOperations(s);
  cout << k << endl;

  return 0;
}
