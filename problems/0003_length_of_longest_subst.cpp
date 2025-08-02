#include "common.hpp"

int lengthOfLongestSubstring(string s) {

  int n = s.size();
  unordered_map<char, int> pos;
  int mx = 1;
  pos[s[0]] = 0;
  int l = 0;
  for (int r = 1; r < n; ++r) {

    if (pos.count(s[r])) {
      int k = pos[s[r]];
      if (l <= k) {
        l = k + 1;
      }
    }

    pos[s[r]] = r;
    mx = max(mx, r - l + 1);
  }
  return mx;
}
int main() {
  string s = "abcabcbb";
  int k = lengthOfLongestSubstring(s);

  cout << k << endl;

  return 0;
}
