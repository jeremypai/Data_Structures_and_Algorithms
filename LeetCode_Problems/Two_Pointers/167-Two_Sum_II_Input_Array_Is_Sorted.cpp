#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int total = numbers[left] + numbers[right];
      if (total == target) {
        return {left + 1, right + 1};
      } else if (total > target) {
        --right;
      } else if (total < target) {
        ++left;
      }
    }
    return {-1, -1};
  }
};