#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;
#include <algorithm>
using std::max;
using std::min;
#include <climits>
#include <set>
#include <unordered_set>
using std::unordered_set;
#include <unordered_map>
using std::unordered_map;
#include <stack>
using std::stack;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <queue>
using std::greater;
using std::priority_queue;
using std::queue;
#include <deque>
using std::deque;
#include <utility>
using std::pair;
using std::swap;
#include <bits/stdc++.h>
using std::array;
#include <optional>
using std::nullopt;
using std::optional;
using opi = std::optional<int>;

template <typename T> struct is_pair : std::false_type {};

template <typename U, typename V>
struct is_pair<std::pair<U, V>> : std::true_type {};

template <typename T> void print_vector(const vector<T> &v) {
  cout << "{";
  for (size_t i = 0; i < v.size(); ++i) {
    // コンパイル時に条件判定
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, std::string>) {
      cout << v[i];
    } else if constexpr (is_pair<T>::value) {
      cout << "(" << v[i].first << "," << v[i].second << ")";
    } else if constexpr (std::is_same_v<T, bool>) {
      cout << (v[i] ? "true" : "false");
    } else {
      print_vector(v[i]);
    }
    if (i + 1 != v.size())
      cout << ",";
  }
  cout << "}" << endl;
}
// 素数列挙関数
vector<int> sieve(int n) {
  vector<bool> isp(n + 1, true);
  vector<int> res;
  res.reserve(n / 2);
  isp[0] = false;
  isp[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isp[i]) {
      for (int j = i; i * j < n + 1; ++j) {
        isp[i * j] = false;
      }
    }
  }
  for (int i = 0; i < n + 1; ++i) {
    if (isp[i]) {
      res.push_back(i);
    }
  }
  return res;
}

/**
 * ListNode
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// vector<int>をListNodeに変換
ListNode *v_to_ln(const vector<int> &a) {
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int x : a) {
    tail->next = new ListNode(x);
    tail = tail->next;
  }
  return dummy.next;
}

// ListNodeを出力
void print_ln(ListNode *head) {
  ListNode *cur = head;
  cout << "(";
  while (cur != nullptr) {

    cout << cur->val;
    if (cur->next) {
      cout << ",";
    }
    cur = cur->next;
  }
  cout << ")" << endl;
}

/**
 * Trees
 *
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// ----- テスト補助：木を作る（レベル順、null可）-----

TreeNode *buildTree(const vector<optional<int>> &a) {
  if (a.empty() || !a[0].has_value())
    return nullptr;
  TreeNode *root = new TreeNode(*a[0]);
  queue<TreeNode *> q;
  q.push(root);
  size_t i = 1;
  while (!q.empty() && i < a.size()) {
    TreeNode *cur = q.front();
    q.pop();
    if (i < a.size()) {
      if (a[i].has_value()) {
        cur->left = new TreeNode(*a[i]);
        q.push(cur->left);
      }
      ++i;
    }
    if (i < a.size()) {
      if (a[i].has_value()) {
        cur->right = new TreeNode(*a[i]);
        q.push(cur->right);
      }
      ++i;
    }
  }
  return root;
}

// ----- 可視化（2Dセンタリング：各段を横位置合わせ）-----
int height(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

void printSpaces(int n) {
  while (n-- > 0)
    cout << ' ';
}

void print_tree(TreeNode *root) {
  if (!root) {
    cout << "(empty)" << endl;
    return;
  }
  int h = height(root);
  queue<TreeNode *> q;
  q.push(root);
  for (int level = 1; level <= h; ++level) {
    int sz = (int)q.size();
    int indent = (1 << (h - level)) - 1;
    int between = (1 << (h - level + 1)) - 1;

    printSpaces(indent);
    vector<TreeNode *> next;
    for (int i = 0; i < sz; ++i) {
      TreeNode *node = q.front();
      q.pop();
      if (node) {
        cout << node->val;
        next.push_back(node->left);
        next.push_back(node->right);
      } else {
        cout << '.';
        next.push_back(nullptr);
        next.push_back(nullptr);
      }
      if (i + 1 < sz)
        printSpaces(between);
    }
    cout << "\n";

    // 次段をキューへ
    bool allNull = true;
    for (auto *x : next) {
      q.push(x);
      if (x)
        allNull = false;
    }
    if (allNull)
      break; // これ以上は全てnull
  }
}
