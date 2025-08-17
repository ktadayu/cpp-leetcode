#include "common.hpp"

TreeNode *invertTree(TreeNode *root) {
  if (!root) {
    return nullptr;
  }
  TreeNode *l = root->left;
  TreeNode *r = root->right;

  TreeNode *l_res = invertTree(l);
  TreeNode *r_res = invertTree(r);

  root->left = r_res;
  root->right = l_res;

  return root;
}

int main() {

  vector<Opt> a = {4, 2, 7, 1, 3, 6, 9};
  TreeNode *root = buildTree(a);

  print_tree(root);

  return 0;
}
