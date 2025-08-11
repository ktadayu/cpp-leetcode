#include "common.hpp"

/*
void segTreeBuild(int node, int left, int right, const vector<int> &baskets,
                  vector<int> &seg) {
  if (left == right) {
    seg[node] = baskets[left];
    return;
  }
  int mid = (left + right) / 2;
  segTreeBuild(node << 1, left, mid, baskets, seg);
  segTreeBuild(node << 1 | 1, mid + 1, right, baskets, seg);
  seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
}
 */

void segTreeBuild_2(int cnt, vector<int> &seg, vector<int> &baskets) {
  int n = baskets.size();
  for (int i = 0; i < n; ++i) {
    seg[cnt + i] = baskets[i];
  }
  for (int i = cnt - 1; i >= 1; --i) {
    seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
  }
}

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {

  int n = baskets.size();
  int cnt = 1;

  while (cnt < n) {
    cnt <<= 1;
  }
  // st = 2^n
  vector<int> seg(2 * cnt, 0);
  segTreeBuild_2(cnt, seg, baskets);

  auto queryFindMost = [&](int q) -> int {
    if (seg[1] < q) {
      return -1;
    }
    int node = 1;
    while (node < cnt) {
      node <<= 1;
      if (seg[node] < q) {
        ++node;
      }
    }
    return node - cnt;
  };

  auto update = [&](int idx) {
    int node = cnt + idx;
    seg[node] = 0;
    for (node >>= 1; node; node >>= 1) {
      seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
    }
  };

  int res = 0;
  for (int q : fruits) {
    int pos = queryFindMost(q);
    if (pos == -1) {
      ++res;
    } else {
      update(pos);
    }
  }

  return res;
}

int main() {
  vector<int> fruits = {4, 2, 5};
  vector<int> baskets = {6, 4, 7};
  int k = numOfUnplacedFruits(fruits, baskets);
  cout << k << endl;

  return 0;
}
