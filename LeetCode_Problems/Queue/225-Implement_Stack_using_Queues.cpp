#include <queue>

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// Time Complexity O(1): pop, top, empty
// Time Complexity O(n): push
// Space Complexity O(n)
class MyStackOneQueueMethod {
  std::queue<int> q_;

 public:
  MyStackOneQueueMethod() {}

  void push(int x) {
    q_.push(x);
    for (int i = 0; i < q_.size() - 1; ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  int pop() {
    int val = q_.front();
    q_.pop();
    return val;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }
};

// Time Complexity O(1): push, empty
// Time Complexity O(n): pop, top
// Space Complexity O(n)
class MyStackTwoQueueMethod {
 private:
  std::queue<int> q1_;
  std::queue<int> q2_;

 public:
  MyStackTwoQueueMethod() {}

  void push(int x) { q1_.push(x); }

  int pop() {
    if (empty()) {
      return -1;
    }

    while (q1_.size() != 1) {
      q2_.push(q1_.front());
      q1_.pop();
    }

    std::swap(q1_, q2_);
    int val = q2_.front();
    q2_.pop();
    return val;
  }

  int top() {
    if (empty()) {
      return -1;
    }

    while (q1_.size() != 1) {
      q2_.push(q1_.front());
      q1_.pop();
    }

    std::swap(q1_, q2_);
    int val = q2_.front();
    q2_.pop();
    q1_.push(val);
    return val;
  }

  bool empty() { return q1_.empty(); }
};
