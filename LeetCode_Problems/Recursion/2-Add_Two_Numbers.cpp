
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
    ListNode *result = new ListNode();
    ListNode *head = result;
    addTwoNumbersInternal(result, l1, l2, 0);
    return head->next;
  }

private:
  void addTwoNumbersInternal(ListNode *result, ListNode *l1, ListNode *l2,
                             int preCarry) {
    if (l1 == nullptr && l2 == nullptr && preCarry == 0) {
      return;
    }

    result->next = new ListNode(preCarry);

    if (l1 != nullptr) {
      result->next->val += l1->val;
      l1 = l1->next;
    }

    if (l2 != nullptr) {
      result->next->val += l2->val;
      l2 = l2->next;
    }

    int carry = result->next->val / 10;
    result->next->val %= 10;
    result = result->next;

    addTwoNumbersInternal(result, l1, l2, carry);
  }
};