#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if (haystack.empty()) {
      return -1;
    }

    if (needle.empty()) {
      return -1;
    }

    if (haystack.length() < needle.length()) {
      return -1;
    }

    for (int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
      if (haystack[i] == needle[0] &&
          haystack.substr(i, needle.length()) == needle) {
        return i;
      }
    }
    return -1;
  }
};