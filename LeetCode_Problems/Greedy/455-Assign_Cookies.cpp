#include <algorithm>
#include <vector>

class Solution {
 public:
  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int gIndex = 0;
    int sIndex = 0;
    while (gIndex < g.size() && sIndex < s.size()) {
      if (s[sIndex] >= g[gIndex]) {
        ++gIndex;
      }
      ++sIndex;
    }
    return gIndex;
  }
};