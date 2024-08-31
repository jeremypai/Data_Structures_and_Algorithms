#include <algorithm>
#include <string>
#include <vector>

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class SolutionTrie {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    // Sort the input list alphabetically
    std::sort(strs.begin(), strs.end());

    // the first element of the array and the last element of the array will
    // have most different prefixes of all comparisons
    std::string first = strs[0];
    std::string last = strs[strs.size() - 1];
    int searchLength = std::min(first.length(), last.length());
    std::string ans;
    for (int i = 0; i < searchLength; ++i) {
      if (first[i] != last[i]) {
        return ans;
      }
      ans += first[i];
    }
    return ans;
  }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class SolutionBruteForce {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string shortStr = strs[0];
    for (const auto& str : strs) {
      if (str.length() < shortStr.length()) {
        shortStr = str;
      }
    }

    for (int i = 0; i < shortStr.length(); ++i) {
      for (const auto& str : strs) {
        if (str[i] != shortStr[i]) {
          return shortStr.substr(0, i);
        }
      }
    }

    return shortStr;
  }
};