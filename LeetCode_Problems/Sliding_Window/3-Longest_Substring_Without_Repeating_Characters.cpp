#include <string>
#include <unordered_set>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) {
      return 0;
    }

    std::unordered_set<char> hashSet;
    int maxLength = 0;
    int left = 0;
    for (int right = 0; right < s.length(); ++right) {
      while (hashSet.find(s[right]) != hashSet.end()) {
        hashSet.erase(s[left]);
        ++left;
      }

      hashSet.insert(s[right]);
      maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};