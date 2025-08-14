#include "common.hpp"

void append(ListNode *&head, int x) {
  if (!head) {
    head = new ListNode(x);
    return;
  }
  ListNode *cur = head;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new ListNode(x);
}

int main() {

  ListNode *head = new ListNode(1);
  append(head, 2);
  append(head, 3);
  ListNode *cur = head;
  while (cur != nullptr) {
    cout << cur->val << ",";
    cur = cur->next;
  }

  return 0;
}
