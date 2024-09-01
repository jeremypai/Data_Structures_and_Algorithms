#include <unordered_map>
#include <vector>

class Solution {
 public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> hashMap;
    int maxFreq = 0;
    for (const auto& task : tasks) {
      ++hashMap[task];
      if (hashMap[task] > maxFreq) {
        maxFreq = hashMap[task];
      }
    }

    int maxFreqCount = 0;
    for (const auto& pair : hashMap) {
      if (pair.second == maxFreq) {
        ++maxFreqCount;
      }
    }

    int ans = (maxFreq - 1) * (n + 1) + maxFreqCount;
    ans = std::max(ans, static_cast<int>(tasks.size()));
    return ans;
  }
};