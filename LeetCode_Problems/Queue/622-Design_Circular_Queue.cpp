#include <vector>

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class MyCircularQueue {
  std::vector<int> array_;
  int front_ = 0;
  int length_ = 0;

 public:
  MyCircularQueue(int k) { array_.resize(k); }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    array_[(front_ + length_) % array_.size()] = value;
    ++length_;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    front_ = (front_ + 1) % array_.size();
    --length_;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return array_[front_];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return array_[(front_ + length_ - 1) % array_.size()];
  }

  bool isEmpty() { return (length_ == 0); }

  bool isFull() { return length_ == array_.size(); }
};
