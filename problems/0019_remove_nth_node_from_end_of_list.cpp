#include "common.hpp"

ListNode *removeNthFromEnd(ListNode *head, int n) {
  // fast
  ListNode *p1 = head;
  int count = 0;
  while (count < n) {
    p1 = p1->next;
    count++;
  }
  ListNode *dummy = new ListNode(0);
  dummy->next = head;
  // slow
  ListNode *p2 = dummy;
  while (p1) {
    p1 = p1->next;
    p2 = p2->next;
  }
  cout << "p1:";
  print_ln(p1);
  cout << "p2:";
  print_ln(p2);
  p2->next = p2->next->next;

  return dummy->next;
}

int main() {
  vector<int> v = {1, 2, 3, 4};
  int n = 2;
  ListNode *l = v_to_ln(v);
  ListNode *h = removeNthFromEnd(l, n);

  print_ln(h);

  return 0;
}
