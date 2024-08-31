// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* cur = dummy;
    ListNode* pointToDel = dummy;

    for (int i = 0; i < n + 1; ++i) {
      cur = cur->next;
    }

    while (cur) {
      cur = cur->next;
      pointToDel = pointToDel->next;
    }

    ListNode* temp = pointToDel->next;
    pointToDel->next = pointToDel->next->next;
    delete temp;

    return dummy->next;
  }
};