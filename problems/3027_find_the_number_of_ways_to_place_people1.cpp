#include "common.hpp"
using namespace std;

int numberOfPairs(vector<vector<int>> &points) {

  sort(points.begin(), points.end(), [](auto &p, auto &q) {
    return (p[0] < q[0]) || (p[0] == q[0] && q[1] < p[1]);
  });
  int n = points.size();

  vector<int> list_y;
  list_y.reserve(n);
  for (int i = 0; i < n; ++i) {
    int curr_y = points[i][1];
    list_y.push_back(curr_y);
  }
  sort(list_y.begin(), list_y.end());
  list_y.erase(unique(list_y.begin(), list_y.end()), list_y.end());

  int l = list_y.size();
  vector<int> nearest_xs(l, -1);
  int count = 0;

  for (int i = 0; i < n;) {
    int x1 = points[i][0];
    int j = i;
    while (j < n && points[j][0] == x1) {
      ++j;
    }
    for (int k = i; k < j; ++k) {
      for (int l = k + 1; l < j; ++l) {
        ++count;
      }
    }
    for (int k = i; k < j; ++k) {
      int y2 = points[k][1];
      int y_idx =
          lower_bound(list_y.begin(), list_y.end(), y2) - list_y.begin();
      int leftmost = -1;
      for (int r = y_idx; r < l; ++r) {
        if (nearest_xs[r] > leftmost) {
          ++count;
          leftmost = nearest_xs[r];
          continue;
        }
      }
    }
    for (int k = i; k < j; ++k) {
      int y2 = points[k][1];
      int r = lower_bound(list_y.begin(), list_y.end(), y2) - list_y.begin();
      if (points[k][0] > nearest_xs[r]) {
        nearest_xs[r] = points[k][0];
      }
    }
    i = j;
  }

  return count;
}

int main() {
  vector<vector<int>> v = {{3, 5}, {6, 3}, {6, 0}};
  int k = numberOfPairs(v);
  cout << k << endl;

  vector<vector<int>> v2 = {{1, 5}, {2, 2}, {3, 3}, {4, 4}, {5, 1}};
  int k2 = numberOfPairs(v2);
  cout << k2 << endl;
  return 0;
}
