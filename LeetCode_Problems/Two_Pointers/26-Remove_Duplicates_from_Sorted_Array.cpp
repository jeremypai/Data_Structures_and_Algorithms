#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[left] != nums[right]) {
        nums[++left] = nums[right];
      }
      ++right;
    }
    return left + 1;
  }
};