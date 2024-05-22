
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *first = head;

    while (true) {
      if (head == nullptr) {
        break;
      }

      if ((head->next != nullptr) && (head->val == head->next->val)) {
        ListNode *temp = head->next;
        head->next = head->next->next;
        delete temp;
        temp = nullptr;
      } else {
        head = head->next;
      }
    }

    return first;
  }
};