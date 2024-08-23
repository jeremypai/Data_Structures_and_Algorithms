#include <vector>

// Better Solution
class SolutionSlidingWindow {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    if (k <= 1) {
      return 0;
    }

    int count = 0;
    int prod = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      prod *= nums[right];
      while (prod >= k) {
        prod /= nums[left];
        ++left;
      }
      // the count of all subarrays ending at the current right position
      count += (right - left) + 1;
    }

    return count;
  }
};

class SolutionTwoPointer {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    int count = 0;
    for (int left = 0; left < nums.size(); ++left) {
      int prod = 1;
      for (int right = left; right < nums.size(); ++right) {
        prod *= nums[right];
        if (prod >= k) {
          break;
        }
        ++count;
      }
    }
    return count;
  }
};