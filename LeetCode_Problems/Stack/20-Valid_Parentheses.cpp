#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> buffer;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        buffer.push(s[i]);
        continue;
      }

      if (buffer.empty()) {
        return false;
      }

      if (s[i] == ')' && buffer.top() != '(') {
        return false;
      }

      if (s[i] == '}' && buffer.top() != '{') {
        return false;
      }

      if (s[i] == ']' && buffer.top() != '[') {
        return false;
      }

      buffer.pop();
    }

    return buffer.empty();
  }
};