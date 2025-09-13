#include "common.hpp"

vector<vector<int>> res;

void add(TreeNode *root) {
  if (!root) {
    return;
  }

  TreeNode *left = root->left;
  TreeNode *right = root->right;

  add(left);
  add(right)
}

vector<vector<int>> levelOrder(TreeNode *root) {}

int main() { return 0; }
