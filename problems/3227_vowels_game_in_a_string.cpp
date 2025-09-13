#include "common.hpp"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPI(i, start, end) for (int i = (start); i < (end); ++i)
#define RREPI(i, end, start) for (int i = (end) - 1; i >= start; --i)
#define EACH(i, is) for (auto &&i : (is))

bool isVowel(char c) {
  return c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'u' || c == 'U' ||
         c == 'e' || c == 'E' || c == 'o' || c == 'O';
}

bool doesAliceWin(string s) {
  int n = s.size();
  int vowelsCnt = 0;
  EACH(c, s) {
    if (isVowel(c)) {
      vowelsCnt++;
    }
  }

  if (vowelsCnt == 0) {
    return false;
  }

  return true;
}

int main() { return 0; }
