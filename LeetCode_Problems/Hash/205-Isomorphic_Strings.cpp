#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }
    return checkIsIsomorphic(s, t) && checkIsIsomorphic(t, s);
  }

 private:
  bool checkIsIsomorphic(const std::string &s1, const std::string &s2) {
    std::unordered_map<char, char> hashMap;
    for (int i = 0; i < s1.length(); ++i) {
      const auto found = hashMap.find(s1[i]);
      if (found != hashMap.end() && found->second != s2[i]) {
        return false;
      } else {
        hashMap[s1[i]] = s2[i];
      }
    }
    return true;
  }
};