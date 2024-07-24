#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> stack;

    for (const auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else {
        if (stack.empty() || (stack.top() == '(' && c != ')') ||
            (stack.top() == '[' && c != ']') ||
            (stack.top() == '{' && c != '}')) {
          return false;
        }

        stack.pop();
      }
    }

    if (!stack.empty()) {
      return false;
    }

    return true;
  }
};