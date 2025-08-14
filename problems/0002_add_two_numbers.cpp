#include "common.hpp"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  ListNode *res = new ListNode();
  ListNode *head = res;
  int c = 0;
  while (l1 || l2) {
    int v1;
    int v2;
    if (!l1) {
      v1 = 0;
    } else {
      v1 = l1->val;
    }
    if (!l2) {
      v2 = 0;
    } else {
      v2 = l2->val;
    }

    int tmp = v1 + v2 + c;
    c = tmp / 10;

    l1 = l1 ? l1->next : nullptr;
    l2 = l2　? l2->next : nullptr;

    head->val = tmp % 10;
    if (l1 || l2) {
      head->next = new ListNode();
      head = head->next;
    } else {
      if (c > 0) {
        head->next = new ListNode(c);
        head = head->next;
      }
    }
  }
  return res;
}
int main() { return 0; }
