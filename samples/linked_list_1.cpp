#include "common.hpp"

int main() {
  // 1→ 2→ 3
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);

  ListNode *cur = head;
  while (cur != nullptr) {
    cout << cur->val << ",";
    cur = cur->next;
  }

  return 0;
}
