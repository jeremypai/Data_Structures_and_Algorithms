// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr1 = headA;
    int lengthA = 0;
    while (ptr1) {
      ++lengthA;
      ptr1 = ptr1->next;
    }

    ListNode *ptr2 = headB;
    int lengthB = 0;
    while (ptr2) {
      ++lengthB;
      ptr2 = ptr2->next;
    }

    ptr1 = headA;
    ptr2 = headB;
    int lengthDiff = lengthA - lengthB;
    if (lengthDiff >= 0) {
      while (true) {
        if (lengthDiff == 0) {
          break;
        }
        ptr1 = ptr1->next;
        --lengthDiff;
      }
    } else {
      lengthDiff = lengthDiff * (-1);
      while (true) {
        if (lengthDiff == 0) {
          break;
        }
        ptr2 = ptr2->next;
        --lengthDiff;
      }
    }

    while (ptr1 && ptr2) {
      if (ptr1 == ptr2) {
        return ptr1;
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    return 0;
  }
};