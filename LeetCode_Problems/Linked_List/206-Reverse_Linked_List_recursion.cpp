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
  ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;
    return reverseListRec(prev, cur);
  }

 private:
  ListNode* reverseListRec(ListNode* prev, ListNode* cur) {
    if (cur == nullptr) {
      return prev;
    }

    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
    return reverseListRec(prev, cur);
  }
};