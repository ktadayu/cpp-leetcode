#include "common.hpp"

int maximum69Number(int num) {
  string s = to_string(num);
  for (char &c : s) {
    if (c == '6') {
      c = '9';
      return stoi(s);
    }
  }
  return stoi(s);
}

int main() {
  int n = 9999;
  int k = maximum69Number(n);
  cout << k << endl;

  return 0;
}
