#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); ++i) {
      int valToFind = target - nums[i];
      const auto& found = hashMap.find(valToFind);
      if (found != hashMap.end()) {
        return {found->second, i};
      }
      hashMap[nums[i]] = i;
    }
    return {};
  }
};