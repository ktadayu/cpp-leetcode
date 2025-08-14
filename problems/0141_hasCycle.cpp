#include "common.hpp"

bool hasCycle(ListNode *head) {
  unordered_set<ListNode *> visited;
  if (!head) {
    return false;
  }
  bool res = true;
  while (!visited.count(head)) {
    if (!head->next) {
      return false;
    }
    visited.insert(head);
    head = head->next;
  }
  return res;
}

int main() { return 0; }
