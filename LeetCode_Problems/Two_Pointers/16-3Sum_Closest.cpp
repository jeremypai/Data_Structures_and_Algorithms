#include <algorithm>
#include <vector>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    // initial value
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int curTotal = nums[i] + nums[left] + nums[right];
        if (std::abs(curTotal - target) < std::abs(ans - target)) {
          ans = curTotal;
        }

        if (curTotal == target) {
          return target;
        } else if (curTotal > target) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return ans;
  }
};