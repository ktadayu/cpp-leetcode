#include "common.hpp"

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);

  print_ln(head);

  vector<int> v = {5, 4, 3, 2, 1};
  ListNode *head_2 = v_to_ln(v);
  print_ln(head_2);

  return 0;
}
