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
#include <deque>
using std::deque;
#include <utility>
using std::pair;
using std::swap;
#include <bits/stdc++.h>
using std::array;

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
