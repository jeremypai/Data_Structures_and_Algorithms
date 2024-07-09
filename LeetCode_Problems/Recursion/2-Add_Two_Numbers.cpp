
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // dummy head
    ListNode *ans = new ListNode(0);

    addNumbersRecursion(l1, l2, ans, 0);
    return ans->next;
  }

private:
  void addNumbersRecursion(ListNode *l1, ListNode *l2, ListNode *ans,
                           int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
      return;
    }

    int accumulate = carry;
    if (l1 != nullptr) {
      accumulate += l1->val;
      l1 = l1->next;
    }

    if (l2 != nullptr) {
      accumulate += l2->val;
      l2 = l2->next;
    }
    carry = accumulate / 10;
    ListNode *temp = new ListNode(accumulate % 10);
    ans->next = temp;
    ans = ans->next;

    addNumbersRecursion(l1, l2, ans, carry);
  }
};