#include "common.hpp"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr && list2 == nullptr) {
    return nullptr;
  }
  if (list1 == nullptr && list2 != nullptr) {
    return list2;
  }
  if (list1 != nullptr && list2 == nullptr) {
    return list1;
  }
  int i1 = list1->val;
  int i2 = list2->val;
  if (i1 > i2) {
    swap(list1, list2);
  }
  // i1 <= i2
  // 現在のheadの追跡
  ListNode *head1 = list1;
  ListNode *head2 = list2;
  ListNode *res = list1;
  while (head1->next && head2) {
    // head1->nextとhead2の比較
    int v1 = head1->next->val;
    int v2 = head2->val;
    ListNode *tmp = head1->next;
    if (v1 >= v2) {
      ListNode *next2 = head2->next;
      head1->next = head2;
      head2->next = tmp;
      head1 = head1->next;
      head2 = next2;
    } else {
      head1 = head1->next;
    }
  }
  if (head2) {
    head1->next = head2;
  }
  return res;
}

int main() { return 0; }
