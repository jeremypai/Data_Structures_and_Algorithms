#include <string>
#include <vector>

class Solution {
 public:
  int numSimilarGroups(std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> groups;
    for (const auto &str : strs) {
      std::vector<int> matchGroup;
      for (int i = 0; i < groups.size(); ++i) {
        for (const auto &strToCompare : groups[i]) {
          int countDiff = 0;
          for (int j = 0; j < str.length(); ++j) {
            if (str[j] != strToCompare[j]) {
              ++countDiff;
            }
          }

          if (countDiff <= 2) {
            matchGroup.emplace_back(i);
          }
        }
      }

      if (matchGroup.empty()) {
        groups.emplace_back(std::vector<std::string>{str});
      } else if (matchGroup.size() == 1) {
        groups[matchGroup[0]].emplace_back(str);
      } else {
        // current string match more than one group -> merge those groups
        for (const auto &group : matchGroup) {
          if (group == matchGroup[0]) {
            continue;
          }

          for (const auto &element : groups[group]) {
            groups[matchGroup[0]].emplace_back(element);
          }
          groups.erase(groups.begin() + group);
        }
      }
    }

    return groups.size();
  }
};