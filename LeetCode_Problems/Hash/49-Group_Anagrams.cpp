#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> hashMap;
    for (const auto &str : strs) {
      std::string sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end());
      const auto found = hashMap.find(sortedStr);
      if (found != hashMap.end()) {
        found->second.emplace_back(str);
      } else {
        hashMap[sortedStr] = std::vector<std::string>{str};
      }
    }

    std::vector<std::vector<std::string>> groups;
    for (const auto &pair : hashMap) {
      groups.emplace_back(pair.second);
    }

    return groups;
  }
};