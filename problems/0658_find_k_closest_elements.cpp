#include "common.hpp"
vector<int> findClosestElements(vector<int> &arr, int k, int x) {
  int left = 0, right = arr.size() - 1;
  int mid = (left + right) / 2;
  while (right != left) {
    if (arr[mid] < x) {
      left = mid;
    }
    if (arr[mid] <= x) {
    }
  }
}
int main() { return 0; }
