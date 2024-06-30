#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#include <iostream>

class QueueArray {
private:
  int *array_ = nullptr;
  int capacity_ = 0;
  int front_ = -1;
  int back_ = -1;

public:
  QueueArray(int size = 30) : capacity_(size) { array_ = new int[capacity_]; }
  ~QueueArray() { delete[] array_; }

  // ------------- Capacity ------------- //
  bool empty() const { return size() == 0; }

  bool full() const { return size() == capacity_; }

  int size() const {
    if (front_ == -1 && back_ == -1) {
      return 0;
    } else if (front_ <= back_) {
      return back_ - front_ + 1;
    }
    // front_ > back_
    return (capacity_ - front_) + (back_ + 1);
  }

  // ---------- Element access ---------- //
  int front() const {
    if (empty()) {
      std::cout << "queue is empty" << std::endl;
      return -1;
    }
    return array_[front_];
  }

  int back() const {
    if (empty()) {
      std::cout << "queue is empty" << std::endl;
      return -1;
    }
    return array_[back_];
  }

  // ------------- Modifiers ------------ //
  void push(int value) {
    if (full()) {
      std::cout << "queue is full" << std::endl;
      return;
    }

    if (empty()) {
      front_ = back_ = 0;
    } else {
      back_ = (back_ + 1) % capacity_;
    }

    array_[back_] = value;
  }

  void pop() {
    if (empty()) {
      std::cout << "queue is already empty" << std::endl;
      return;
    }

    if (size() == 1) {
      front_ = -1;
      back_ = -1;
    } else {
      front_ = (front_ + 1) % capacity_;
    }
  }
};

#endif // ! QUEUE_ARRAY_H_