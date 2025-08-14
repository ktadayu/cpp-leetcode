#include "common.hpp"

ListNode *reverseList(ListNode *head) {
  ListNode *curr = head;
  ListNode *prev = nullptr;
  while (curr) {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

ListNode *build(const vector<int> &a) {
  ListNode dummy;          // 番兵
  ListNode *tail = &dummy; // 末尾を指す
  for (int x : a) {
    tail->next = new ListNode(x);
    tail = tail->next;
  }
  return dummy.next; // 先頭
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  ListNode *head = build(v);
  ListNode *res = reverseList(head);
  ListNode *cur = res;
  while (cur != nullptr) {
    cout << cur->val << ",";
    cur = cur->next;
  }
  return 0;
}
