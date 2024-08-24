#include <string>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    int maxLength = 0;
    std::unordered_map<char, int> hashMap;
    int left = 0;
    for (int right = 0; right < s.length(); ++right) {
      ++hashMap[s[right]];
      while (hashMap.size() > k) {
        if (--hashMap[s[left]] == 0) {
          hashMap.erase(s[left]);
        }
        ++left;
      }

      maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};