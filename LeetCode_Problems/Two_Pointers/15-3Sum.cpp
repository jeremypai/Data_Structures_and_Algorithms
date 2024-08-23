#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = nums[i] * (-1);
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int total = nums[left] + nums[right];
        if (total == target) {
          ans.emplace_back(std::vector<int>{-target, nums[left], nums[right]});

          int curLeft = nums[left];
          int curRight = nums[right];
          while (left < right && nums[left] == curLeft) {
            ++left;
          }

          while (left < right && nums[right] == curRight) {
            --right;
          }
        } else if (total > target) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return ans;
  }
};