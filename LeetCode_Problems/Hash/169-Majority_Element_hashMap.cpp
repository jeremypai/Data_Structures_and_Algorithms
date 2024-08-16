#include <unordered_map>
#include <vector>

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> hashMap;
    for (const auto& num : nums) {
      ++hashMap[num];
      if (hashMap[num] > nums.size() / 2) {
        return num;
      }
    }
    return -1;
  }
};