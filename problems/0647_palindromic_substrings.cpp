#include "common.hpp"

void getEvenLength(int &curr_res, string &s, vector<pair<int, int>> &v) {
  if (v.size() == 0) {
    return;
  }
  vector<pair<int, int>> vp;
  for (auto e : v) {
    if (e.first == 0 || e.second == s.size() - 1) {
      continue;
    }
    int l = e.first - 1;
    int r = e.second + 1;
    if (s[l] == s[r]) {
      vp.push_back({l, r});
    }
  }
  curr_res += vp.size();
  cout << "vp:";
  print_vector(vp);

  getEvenLength(curr_res, s, vp);

  return;
}

int getOddLength(string &s, vector<pair<int, int>> &v) {}

int countSubstrings(string s) {
  vector<pair<int, int>> first, second;
  int res = s.size();
  for (int i = 0; i < s.size(); ++i) {
    first.push_back({i, i});
    if (i < s.size() - 1 && s[i] == s[i + 1]) {
      second.push_back({i, i + 1});
    }
  }
  print_vector(first);
  print_vector(second);

  res += second.size();

  getEvenLength(res, s, second);
  getEvenLength(res, s, first);

  return res;
}

int main() {
  string s = "aaa";
  int res = countSubstrings(s);
  cout << res << endl;
  return 0;
}
