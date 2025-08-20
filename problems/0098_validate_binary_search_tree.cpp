#include "common.hpp"

bool search(TreeNode *n, long long mn, long long mx) {
  if (!n) {
    return true;
  }
  long long v = n->val;
  if (v <= mn || v >= mx) {
    return false;
  }
  return search(n->left, mn, v) && search(n->right, v, mx);
}

bool isValidBST(TreeNode *root) {
  long long mn = LLONG_MIN;
  long long mx = LLONG_MAX;
  return search(root, mn, mx);
}

int main() { return 0; }
