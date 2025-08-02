#include "common.hpp"

int subarrayBitwiseORs(vector<int> &arr) {
  int n = arr.size();
  unordered_set<int> res, prev, curr;
  int mx = 0;

  res.insert(arr[0]);
  prev.insert(arr[0]);

  for (int i = 1; i < n; ++i) {
    res.insert(arr[i]);
    curr.clear();
    curr.insert(arr[i]);
    for (int k : prev) {
      curr.insert(k | arr[i]);
      res.insert(k | arr[i]);
    }
    prev = curr;
  }
  /*
  for (int i = n - 1; i >= 0; --i) {
    mx = mx | arr[i];
    int curr = arr[i];
    us.insert(curr);
    int j = 1;
    while (curr != mx && i + j < n) {
      curr = curr | arr[i + j];
      us.insert(curr);
      ++j;
    }
  }
  */
  for (int i : res) {
    cout << i << endl;
  }
  return res.size();
}

int main() {
  vector<int> arr = {1, 1, 2};
  //  vector<int> arr = {1, 2, 4};

  int k = subarrayBitwiseORs(arr);
  cout << "ans:" << k << endl;
  return 0;
}
