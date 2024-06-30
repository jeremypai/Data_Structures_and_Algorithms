#ifndef QUEUE_LINKED_LIST_H_
#define QUEUE_LINKED_LIST_H_

#include <iostream>

typedef struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
} Node;

class QueueLinkedList {
private:
  Node *front_ = nullptr;
  Node *back_ = nullptr;
  int size_ = 0;

public:
  QueueLinkedList() {}
  ~QueueLinkedList() {
    while (!empty()) {
      pop();
    }
  }

  // ------------- Capacity ------------- //
  bool empty() const { return (front_ == nullptr && back_ == nullptr); }

  int size() const { return size_; }

  // ---------- Element access ---------- //
  int front() const {
    if (empty()) {
      std::cout << "queue is empty" << std::endl;
      return -1;
    }
    return front_->val;
  }

  int back() const {
    if (empty()) {
      std::cout << "queue is empty" << std::endl;
      return -1;
    }
    return back_->val;
  }

  // ------------- Modifiers ------------ //
  void push(int value) {
    Node *newNode = new Node(value);
    ++size_;

    if (empty()) {
      front_ = back_ = newNode;
    } else {
      back_->next = newNode;
      back_ = back_->next;
    }
  }

  void pop() {
    if (empty()) {
      std::cout << "queue is already empty" << std::endl;
      return;
    }

    Node *deletedNode = front_;
    front_ = front_->next;
    delete deletedNode;
    --size_;

    if (front_ == nullptr) {
      back_ = nullptr;
    }
  }
};

#endif // ! QUEUE_LINKED_LIST_H_