#include "common.hpp"

class Trie {
  static constexpr int alpha_count = 26;
  // next[node][moji] :a node from node to moji;
  vector<array<int, alpha_count>> next;
  vector<char> isWord;

public:
  Trie() {
    next.emplace_back();
    next[0].fill(-1);
    isWord.emplace_back(0);
  }

  void insert(string word) {
    int u = 0;
    for (char &c : word) {
      int k = c - 'a';
      if (next[u][k] == -1) {
        int v = next.size();
        next.emplace_back();
        next.back().fill(-1);
        isWord.emplace_back(0);
        next[u][k] = v;
      }
      u = next[u][k];
    }
    isWord[u] = 1;
    print_vector(next);
    print_vector(isWord);
  }

  bool search(string word) {
    int u = 0;
    for (char c : word) {
      int k = c - 'a';
      if (k < 0 || k >= 26) {
        return false;
      }
      int v = next[u][k];
      if (v == -1) {
        return false;
      }
      u = v;
    }

    return isWord[u];
  }

  bool startsWith(string prefix) {
    int u = 0;
    for (char c : prefix) {
      int k = c - 'a';
      if (k < 0 || k >= 26) {
        return false;
      }
      int v = next[u][k];
      if (v == -1) {
        return false;
      }
      u = v;
    }

    return true;
  }

  vector<int> getPathNodeIds(const string &word) const {
    int u = 0;
    std::vector<int> ids;
    for (char c : word) {
      int k = c - 'a';
      if (k < 0 || k >= 26)
        return {};
      int v = next[u][k];
      if (v == -1)
        return {};
      ids.push_back(v);
      u = v;
    }
    return ids;
  }
};

int main() {
  Trie *trie = new Trie();
  trie->insert("app");
  trie->insert("apple");
  trie->insert("abcdefghijklmnopqrstuvwz");
  trie->insert("cap");
  trie->insert("bat");
  vector<int> app = trie->getPathNodeIds("app");
  vector<int> bat = trie->getPathNodeIds("bat");
  print_vector(app);
  print_vector(bat);

  bool res = trie->search("app");
  cout << res << endl;
  bool res2 = trie->startsWith("apl");
  cout << res2 << endl;
  return 0;
}
