#include "common.hpp"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPI(i, start, end) for (int i = (start); i < (end); ++i)
#define RREPI(i, end, start) for (int i = (end) - 1; i >= start; --i)
#define EACH(i, is) for (auto &&i : (is))

bool isVowel(char c) {
  return c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'u' || c == 'U' ||
         c == 'e' || c == 'E' || c == 'o' || c == 'O';
}

int maxFreqSum(string s) {

  unordered_map<char, int> um;
  int mxV = 0;
  int mxC = 0;
  EACH(c, s) {
    um[c]++;
    if (isVowel(c)) {
      mxV = max(um[c], mxV);
    } else {
      mxC = max(um[c], mxC);
    }
  }

  return mxV + mxC;
}

int main() {

  string s = "aeiaeia";
  int k = maxFreqSum(s);

  cout << k << endl;

  return 0;
}
