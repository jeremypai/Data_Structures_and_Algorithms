#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> hashSet;
    while (head) {
      if (hashSet.find(head) != hashSet.end()) {
        return true;
      }
      hashSet.insert(head);
      head = head->next;
    }
    return false;
  }
};