#include <string>

class Solution {
 private:
  bool oneCharToMiss_ = true;

 public:
  bool validPalindrome(std::string s) {
    return validPalindromeRecursion(s, 0, s.length() - 1);
  }

 private:
  bool validPalindromeRecursion(const std::string &s, int begin, int end) {
    int left = begin;
    int right = end;

    while (true) {
      if (left > right) {
        break;
      }

      if (s[left] != s[right]) {
        if (oneCharToMiss_) {
          oneCharToMiss_ = false;
          return validPalindromeRecursion(s, left, right - 1) ||
                 validPalindromeRecursion(s, left + 1, right);
        } else {
          return false;
        }
      }

      ++left;
      --right;
    }

    return true;
  }
};