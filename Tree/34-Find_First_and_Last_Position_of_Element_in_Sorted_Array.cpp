#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }

    int left = searchLeftTarget(nums, target, 0, nums.size() - 1);
    int right = searchRightTarget(nums, target, 0, nums.size() - 1);
    return {left, right};
  }

private:
  int searchLeftTarget(const std::vector<int> &nums, int target, int left,
                       int right) {
    int result = -1;
    while (left <= right) {
      int middle = (left + right) / 2;
      if (nums[middle] == target) {
        result = middle;
        right = middle - 1;
      } else if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    return result;
  }

  int searchRightTarget(const std::vector<int> &nums, int target, int left,
                        int right) {
    int result = -1;
    while (left <= right) {
      int middle = (left + right) / 2;
      if (nums[middle] == target) {
        result = middle;
        left = middle + 1;
      } else if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    return result;
  }
};