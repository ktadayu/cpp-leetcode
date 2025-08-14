#include "common.hpp"

struct ArrHash {
  size_t operator()(const array<int, 26> &a) const noexcept {
    size_t h = 0;
    for (int x : a) {
      size_t k = std::hash<int>{}(x);
      h ^= k + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    }
    return h;
  }
};

vector<vector<string>> groupAnagrams(vector<string> &strs) {

  unordered_map<array<int, 26>, vector<string>, ArrHash> um;
  um.reserve(strs.size());

  for (string &s : strs) {
    array<int, 26> k{};
    for (unsigned char c : s) {
      k[c - 'a']++;
    }
    um[k].push_back(s);
  }

  vector<vector<string>> res;
  res.reserve(strs.size());

  for (auto &v : um) {
    res.emplace_back(move(v.second));
  }

  for (auto &[u, v] : um) {
    // array<int,26> の出力
    cout << "{";
    for (size_t i = 0; i < u.size(); ++i) {
      if (i)
        cout << ",";
      cout << u[i];
    }
    cout << "} ";

    // vector<string> の出力
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
      if (i)
        cout << ",";
      cout << v[i];
    }
    cout << "]\n";
  }

  return res;
}

int main() {
  vector<string> strs = {"str", "hello", "elloh"};
  vector<vector<string>> v = groupAnagrams(strs);
  print_vector(v);
  return 0;
}
