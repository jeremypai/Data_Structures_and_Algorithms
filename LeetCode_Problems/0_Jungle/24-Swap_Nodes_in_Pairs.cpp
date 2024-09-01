// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class SolutionRec {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    if (head->next == nullptr) {
      return head;
    }

    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
  }
};

class SolutionIter {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    if (head->next == nullptr) {
      return head;
    }

    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur = dummy->next;
    while (cur && cur->next) {
      ListNode* next = cur->next;
      pre->next = next;
      cur->next = next->next;
      next->next = cur;

      pre = pre->next->next;
      cur = cur->next;
    }

    return dummy->next;
  }
};