#include <cmath>
#include <vector>

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> ans(nums.size(), 0);
    int index = nums.size() - 1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int leftSq = std::pow(nums[left], 2);
      int rightSq = std::pow(nums[right], 2);
      if (leftSq >= rightSq) {
        ans[index--] = leftSq;
        ++left;
      } else {
        ans[index--] = rightSq;
        --right;
      }
    }
    return ans;
  }
};