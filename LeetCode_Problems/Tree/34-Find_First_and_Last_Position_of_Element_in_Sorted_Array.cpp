#include <vector>

class Solution {
 private:
  std::vector<int> ans = {-1, -1};

 public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    searchLeftMostValue(nums, target, 0, nums.size() - 1);
    searchRightMostValue(nums, target, 0, nums.size() - 1);
    return ans;
  }

 private:
  void searchLeftMostValue(const std::vector<int> &nums, int target, int start,
                           int end) {
    if (start > end) {
      return;
    }

    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      ans[0] = mid;
      searchLeftMostValue(nums, target, start, mid - 1);
    } else if (nums[mid] < target) {
      searchLeftMostValue(nums, target, mid + 1, end);
    } else {
      searchLeftMostValue(nums, target, start, mid - 1);
    }
  }

  void searchRightMostValue(const std::vector<int> &nums, int target, int start,
                            int end) {
    if (start > end) {
      return;
    }

    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      ans[1] = mid;
      searchRightMostValue(nums, target, mid + 1, end);
    } else if (nums[mid] < target) {
      searchRightMostValue(nums, target, mid + 1, end);
    } else {
      searchRightMostValue(nums, target, start, mid - 1);
    }
  }
};