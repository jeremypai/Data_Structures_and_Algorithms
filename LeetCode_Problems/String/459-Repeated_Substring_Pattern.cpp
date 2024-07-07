#include <string>

class Solution {
public:
  bool repeatedSubstringPattern(std::string s) {
    if (s.empty()) {
      return false;
    }

    for (int i = 1; i <= s.length() / 2; ++i) {
      if (s.length() % i != 0) {
        continue;
      }

      std::string subStr = s.substr(0, i);
      bool ans = true;
      for (int j = 0; j < s.length() / subStr.length(); ++j) {
        if (s.substr(j * subStr.length(), subStr.length()) != subStr) {
          ans = false;
          break;
        }
      }

      if (ans) {
        return true;
      }
    }

    return false;
  }
};