#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

#include <iostream>

class StackArray {
private:
  int *array_ = nullptr;
  int capacity_ = 0;
  int frontIndex_ = -1;

public:
  StackArray(int size = 30) : capacity_(size) { array_ = new int[capacity_]; }
  ~StackArray() { delete[] array_; }

  // ------------- Capacity ------------- //
  bool empty() const { return size() == 0; }

  bool full() const { return size() == capacity_; }

  int size() const { return frontIndex_ + 1; }

  // ---------- Element access ---------- //
  int top() const {
    if (empty()) {
      std::cout << "stack is empty" << std::endl;
      return -1;
    }
    return array_[frontIndex_];
  }

  // ------------- Modifiers ------------ //
  void push(int value) {
    if (full()) {
      std::cout << "stack is full" << std::endl;
      return;
    }
    array_[++frontIndex_] = value;
  }

  void pop() {
    if (empty()) {
      std::cout << "stack is already empty" << std::endl;
      return;
    }
    --frontIndex_;
  }
};

#endif // ! STACK_ARRAY_H_