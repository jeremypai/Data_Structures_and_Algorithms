#include <algorithm>
#include <vector>

// Time Complexity: O(n*logn)
// Space Complexity: O(1)
class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};