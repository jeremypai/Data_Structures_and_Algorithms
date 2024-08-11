// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* cur_ = nullptr;
  bool ans_ = true;

 public:
  bool isPalindrome(ListNode* head) {
    cur_ = head;
    isPalindromeRec(head);
    return ans_;
  }

 private:
  void isPalindromeRec(ListNode* rec) {
    if (rec == nullptr) {
      return;
    }

    isPalindromeRec(rec->next);
    if (!ans_) {
      return;
    }

    ans_ = (rec->val == cur_->val);
    cur_ = cur_->next;
  }
};