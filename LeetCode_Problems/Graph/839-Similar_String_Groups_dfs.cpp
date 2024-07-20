#include <string>
#include <vector>

class Solution {
public:
  int numSimilarGroups(std::vector<std::string> &strs) {
    int ans = 0;
    std::vector<bool> visited(strs.size(), false);
    for (int i = 0; i < strs.size(); ++i) {
      if (!visited[i]) {
        ++ans;
        dfs(strs, visited, i);
      }
    }
    return ans;
  }

private:
  void dfs(const std::vector<std::string> &strs, std::vector<bool> &visited,
           int index) {
    if (visited[index]) {
      return;
    }

    visited[index] = true;

    for (int i = 0; i < strs.size(); ++i) {
      if (isSimilar(strs[index], strs[i])) {
        dfs(strs, visited, i);
      }
    }
  }

  bool isSimilar(const std::string &str1, const std::string &str2) {
    int countDiff = 0;
    for (int i = 0; i < str1.length(); ++i) {
      if (str1[i] != str2[i]) {
        ++countDiff;
      }
    }

    return (countDiff <= 2);
  }
};