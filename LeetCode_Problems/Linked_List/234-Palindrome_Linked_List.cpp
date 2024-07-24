#include <stack>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) {
      return true;
    }

    if (head->next == nullptr) {
      return true;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    std::stack<int> s;
    while (true) {
      if (fast == nullptr || fast->next == nullptr) {
        break;
      }
      s.push(slow->val);
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast != nullptr) {
      // odd sequence
      slow = slow->next;
    }

    while (true) {
      if (slow == nullptr) {
        break;
      }

      if (s.top() != slow->val) {
        return false;
      }

      s.pop();
      slow = slow->next;
    }
    return true;
  }
};