#include "common.hpp"

const int MOD = 1e9 + 7;

int peopleAwareOfSecret(int n, int delay, int forget) {
  vector<long long> cntPeople(n + 1, 0);
  cntPeople[1] = 1;

  queue<int> q;
  vector<bool> inQuee(n + 1, false);
  q.push(1);
  inQuee[1] = true;

  while (!q.empty()) {
    int start = q.front();
    q.pop();
    inQuee[start] = false;

    long long cnt = cntPeople[start];
    if (cnt == 0) {
      continue;
    }
    int end = start + forget;

    for (int i = start + delay; i < end && i < n + 1; ++i) {
      cntPeople[i] = (cntPeople[i] + cnt) % MOD;
      if (!inQuee[i]) {
        q.push(i);
        inQuee[i] = true;
      }
    }
  }

  int res = 0;
  for (int i = max(1, n - forget + 1); i < n + 1; ++i) {
    res = (res + cntPeople[i]) % MOD;
  }

  return res;
}

int main() {
  int n = 6;
  int delay = 2;
  int forget = 4;
  int k = peopleAwareOfSecret(n, delay, forget);
  cout << k << endl;

  return 0;
}
