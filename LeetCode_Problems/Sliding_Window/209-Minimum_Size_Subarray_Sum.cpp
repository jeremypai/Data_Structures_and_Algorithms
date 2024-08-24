#include <limits>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int minLength = std::numeric_limits<int>::max();
    int total = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      total += nums[right];
      while (total >= target) {
        minLength = std::min(minLength, right - left + 1);
        total -= nums[left];
        ++left;
      }
    }
    return minLength != std::numeric_limits<int>::max() ? minLength : 0;
  }
};