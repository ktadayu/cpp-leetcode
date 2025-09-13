#include "common.hpp"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPI(i, start, end) for (int i = (start); i < (end); ++i)
#define RREPI(i, end, start) for (int i = (end) - 1; i >= start; --i)
#define EACH(i, is) for (auto &&i : (is))

using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'u' || c == 'U' ||
         c == 'e' || c == 'E' || c == 'o' || c == 'O';
}

string sortVowels(string s) {

  int n = s.size();
  string vows;
  REP(i, n) {
    if (isVowel(s[i])) {
      cout << s[i] << endl;
      vows += s[i];
      s[i] = '*';
    }
  }

  if (vows.size() == 0) {
    return s;
  }

  sort(vows.begin(), vows.end());

  int i = 0;
  EACH(c, s) {
    if (c == '*') {
      c = vows[i++];
    }
  }
  return s;
}

int main() {
  // int i = 'A';
  // int j = 'z';
  // cout << i << endl;
  // cout << j << endl;
  string s = "lEetcOde";

  string res = sortVowels(s);
  cout << res << endl;
  return 0;
}
