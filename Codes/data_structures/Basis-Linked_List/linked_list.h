#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node* next) : val(val), next(next) {}
};

#endif  // !LINKED_LIST_H_