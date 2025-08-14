#include "common.hpp"

void reorderList(ListNode *head) {
  // 前半と後半に分ける
  // 前半の頭:l1
  // 後半の頭:l2
  ListNode *l1 = head;
  ListNode *l2 = head;
  ListNode *cur1 = l1;
  ListNode *cur2 = l2;
  while (cur2 && cur2->next) {
    cur2 = cur2->next->next;
    cur1 = cur1->next;
  }
  l2 = cur1->next;
  cur1->next = nullptr;
  print_ln(l1);
  print_ln(l2);

  // l2をreverseする
  ListNode *rev = l2;
  ListNode *prev = nullptr;
  while (rev) {
    ListNode *next = rev->next;
    rev->next = prev;
    prev = rev;
    rev = next;
  }
  print_ln(prev);

  // l1とprevをつなげる
  while (prev) {
    ListNode *tmp = l1->next;
    ListNode *tmp2 = prev->next;
    l1->next = prev;
    prev->next = tmp;
    prev = tmp2;
    l1 = tmp;
  }
  print_ln(head);
}

int main() {
  vector<int> v = {1, 2, 3, 4};
  ListNode *head = v_to_ln(v);
  reorderList(head);

  return 0;
}
