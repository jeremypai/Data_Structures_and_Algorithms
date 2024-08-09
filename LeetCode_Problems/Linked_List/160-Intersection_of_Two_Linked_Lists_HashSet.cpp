#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::unordered_set<ListNode *> hashSet;
    while (headA) {
      hashSet.insert(headA);
      headA = headA->next;
    }

    while (headB) {
      if (hashSet.find(headB) != hashSet.end()) {
        return headB;
      }
      headB = headB->next;
    }
    return 0;
  }
};