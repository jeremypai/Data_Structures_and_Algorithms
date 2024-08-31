#include <string>
#include <unordered_set>

// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionSlidingWindowWithHashSet {
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

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class SolutionSlidingWindowWithSubStr {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int ans = 0;
    int left = 0;
    for (int right = 0; right < s.length(); ++right) {
      while (left < right) {
        std::string subStr = s.substr(left, right - left);
        if (subStr.find(s[right]) == std::string::npos) {
          break;
        }
        ++left;
      }
      ans = std::max(ans, right - left + 1);
    }
    return ans;
  }
};