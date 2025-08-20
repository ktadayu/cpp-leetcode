#include "common.hpp"

vector<vector<int>> merge(vector<vector<int>> &intervals) {

  sort(intervals.begin(), intervals.end(),
       [](auto &p, auto &q) { return p[0] < q[0]; });
  int l = intervals[0][0];
  int r = intervals[0][1];
  vector<vector<int>> res;
  for (auto &i : intervals) {
    if (i[0] <= r) {
      r = max(r, i[1]);
    } else {
      res.push_back(vector<int>{l, r});
      l = i[0];
      r = i[1];
    }
  }
  res.push_back(vector<int>{l, r});

  return res;
}

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res = merge(intervals);
  print_vector(res);

  return 0;
}
