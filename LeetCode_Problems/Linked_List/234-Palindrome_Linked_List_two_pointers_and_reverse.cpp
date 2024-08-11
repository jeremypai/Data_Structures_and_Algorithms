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
  bool isPalindrome(ListNode* head) {
    // traverse to the middle of the list
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast) {
      slow = slow->next;
    }

    // reverse the list after node that slow pointer pointing at
    ListNode* prev = nullptr;
    ListNode* cur = slow;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    while (prev) {
      if (prev->val != head->val) {
        return false;
      }

      prev = prev->next;
      head = head->next;
    }

    return true;
  }
};