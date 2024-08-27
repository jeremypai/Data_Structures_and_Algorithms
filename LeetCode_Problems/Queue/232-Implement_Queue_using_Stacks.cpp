#include <stack>

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Time Complexity O(n): push
// Time Complexity O(1): pop, peek, empty
// Space Complexity O(n)
class MyQueue {
  std::stack<int> s1_;
  std::stack<int> s2_;

 public:
  MyQueue() {}

  void push(int x) {
    while (!s1_.empty()) {
      s2_.push(s1_.top());
      s1_.pop();
    }

    s1_.push(x);

    while (!s2_.empty()) {
      s1_.push(s2_.top());
      s2_.pop();
    }
  }

  int pop() {
    int val = s1_.top();
    s1_.pop();
    return val;
  }

  int peek() { return s1_.top(); }

  bool empty() { return s1_.empty(); }
};
