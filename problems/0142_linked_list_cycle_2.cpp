#include "common.hpp"

ListNode *detectCycle(ListNode *head) {
  ListNode *h1 = head;
  ListNode *h2 = head;
  while (h1) {
    h1 = h1->next;
    if (!h1) {
      return nullptr;
    }
    h1 = h1->next;
    h2 = h2->next;
    if (!h2) {
      return nullptr;
    }
    if (h1 == h2) {
      ListNode *p1 = h1;
      ListNode *p2 = head;
      while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
      }
      return p1;
    }
  }
  return nullptr;
}

int main() { return 0; }
