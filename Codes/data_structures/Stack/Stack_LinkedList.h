#ifndef STACK_LINKED_LIST_H_
#define STACK_LINKED_LIST_H_

#include <iostream>

typedef struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
} Node;

class StackLinkedList {
private:
  Node *list_ = nullptr;
  int size_ = 0;

public:
  StackLinkedList() {}
  ~StackLinkedList() {
    while (!empty()) {
      pop();
    }
  }

  // ------------- Capacity ------------- //
  bool empty() const { return list_ == nullptr; }

  int size() const { return size_; }

  // ---------- Element access ---------- //
  int top() const {
    if (empty()) {
      std::cout << "stack is empty" << std::endl;
      return -1;
    }
    return list_->val;
  }

  // ------------- Modifiers ------------ //
  void push(int value) {
    Node *newNode = new Node(value, list_);
    list_ = newNode;
    ++size_;
  }

  void pop() {
    if (empty()) {
      std::cout << "stack is already empty" << std::endl;
      return;
    }

    Node *deletedNode = list_;
    list_ = list_->next;
    delete deletedNode;
    --size_;
  }
};

#endif // ! STACK_LINKED_LIST_H_