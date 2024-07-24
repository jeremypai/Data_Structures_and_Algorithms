#include <unordered_map>

// Definition for a Node.
class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }

    std::unordered_map<Node *, Node *> hashMap;

    Node *cur = head;
    while (true) {
      if (cur == nullptr) {
        break;
      }

      hashMap[cur] = new Node(cur->val);
      cur = cur->next;
    }

    cur = head;
    while (true) {
      if (cur == nullptr) {
        break;
      }

      hashMap[cur]->next = hashMap[cur->next];
      hashMap[cur]->random = hashMap[cur->random];

      cur = cur->next;
    }

    return hashMap[head];
  }
};