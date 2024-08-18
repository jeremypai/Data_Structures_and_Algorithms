#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    // check if the target exists
    if (left < 0 || left >= nums.size() || nums[left] != target) {
      return {-1, -1};
    }
    int leftRangeIndex = left;

    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return {leftRangeIndex, left - 1};
  }
};

class SolutionByOfficialFunction {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    const auto lower = std::lower_bound(nums.begin(), nums.end(), target);
    const auto upper = std::upper_bound(nums.begin(), nums.end(), target);
    if (lower == nums.end() || *lower != target) {
      return {-1, -1};
    }

    int lowerIndex = std::distance(nums.begin(), lower);
    int upperIndex = std::distance(nums.begin(), upper) - 1;
    return {lowerIndex, upperIndex};
  }
};