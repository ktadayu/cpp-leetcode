#include "common.hpp"

int maxDepth(TreeNode *root) {
  if (!root) {
    return 0;
  }
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);

  int k = max(l, r) + 1;

  return k;
}

int main() {

  vector<opi> v = {3, 9, 20, nullopt, nullopt, 15, 7};
  TreeNode *root = buildTree(v);
  int k = maxDepth(root);
  cout << k << endl;

  return 0;
}
