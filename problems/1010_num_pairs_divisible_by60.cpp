#include "common.hpp"
// 以下の解法以外に単純に手前から走査して、mpを用いてそこまでのペアを逐次計算する方法があって、それが簡単だし速い
int numPairsDivisibleBy60(vector<int> &time) {
  int n = time.size();
  unordered_map<int, int> um;
  for (int i = 0; i < n; ++i) {
    time[i] = time[i] % 60;
    um[time[i]]++;
  }
  int cnt = 0;
  for (int i = 1; i < 30; ++i) {
    int l = um[i];
    int r = um[60 - i];
    cnt = cnt + l * r;
  }
  if (um[30] > 1) {
    cnt = cnt + um[30] * (um[30] - 1) / 2;
  }
  if (um[0] > 1) {
    cnt = cnt + um[0] * (um[0] - 1) / 2;
  }
  return cnt;
}
int main() {
  //  vector<int> time = {30, 20, 150, 100, 40};
  vector<int> time = {60, 60, 60};
  int k = numPairsDivisibleBy60(time);
  cout << k << endl;

  return 0;
}
