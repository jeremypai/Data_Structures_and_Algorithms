#include <string>

// TODO Dynamic Programming

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    std::string ans;
    for (int i = 0; i < s.length(); ++i) {
      std::string oddStr = expandFromCenter(s, i, i);
      std::string evenStr = expandFromCenter(s, i, i + 1);
      if (oddStr.length() > ans.length()) {
        ans = oddStr;
      }

      if (evenStr.length() > ans.length()) {
        ans = evenStr;
      }
    }
    return ans;
  }

 private:
  std::string expandFromCenter(const std::string& str, int left, int right) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
      --left;
      ++right;
    }
    return str.substr(left + 1, right - left - 1);
  }
};

// Time Complexity: O(n^3)
// Space Complexity: O(1)
class SolutionBruteForce {
 public:
  std::string longestPalindrome(std::string s) {
    std::string ans;
    for (int i = 0; i < s.length(); ++i) {
      for (int j = i; j < s.length(); ++j) {
        std::string cur = s.substr(i, (j - i) + 1);
        if (isPalindrome(cur)) {
          if (cur.length() > ans.length()) {
            ans = cur;
          }
        }
      }
    }
    return ans;
  }

 private:
  bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
      if (str[left] != str[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};