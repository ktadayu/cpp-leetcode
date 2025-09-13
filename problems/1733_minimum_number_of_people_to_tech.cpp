#include "common.hpp"
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPI(i, start, end) for (int i = (start); i < (end); ++i)
#define RREPI(i, end, start) for (int i = (end) - 1; i >= start; --i)
#define EACH(i, is) for (auto &i : (is))

int minimumTeachings(int n, vector<vector<int>> &languages,
                     vector<vector<int>> &friendships) {
  int ls = languages.size();

  vector<pair<int, int>> targets;
  EACH(f, friendships) {
    int u = f[0] - 1, v = f[1] - 1;
    bool canConnect = false;
    EACH(lang1, languages[u]) {
      EACH(lang2, languages[v]) {
        if (lang1 == lang2) {
          canConnect = true;
          break;
        }
      }
      if (canConnect) {
        break;
      }
      if (!canConnect) {
        targets.push_back({u, v});
      }
    }
    vector<bool> check(m, false);
    EACH(pair, targets) {
      check[pair.first] = true;
      check[pair.second] = true;
    }

    int size = 0;
    REP(i, m) {
      if (check[i]) {
        size++;
      }
    }

    vector<int> langCnt(n + 1, 0);
    REP(i, m) {
      if (check[i]) {
        for (int lang : languages[i]) {
          langCnt[lang]++;
        }
      }
    }
    int cnt = 0;
    REP(i, n + 1) { cnt = max(cnt, langCnt[i]); }
  }
  return size - cnt;
}

int main() { return 0; }
