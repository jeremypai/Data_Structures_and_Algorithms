#include <limits>
#include <vector>

// Better solution
// Time Complexity: O(n)
class SolutionSlidingWindow {
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

// Time Complexity: O(nlogn)
class SolutionPrefixSumWithBinarySearch {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    std::vector<int> psum(nums.size() + 1, 0);
    for (int i = 1; i < nums.size() + 1; ++i) {
      // store value from index 0 to index i-1
      psum[i] = psum[i - 1] + nums[i - 1];
    }

    int minLength = std::numeric_limits<int>::max();
    for (int i = 0; i < psum.size(); ++i) {
      const auto lower =
          std::lower_bound(psum.begin() + i, psum.end(), target + psum[i]);
      int lowerIndex = std::distance(psum.begin(), lower);
      if (lowerIndex >= psum.size()) {
        break;
      }
      minLength = std::min(minLength, lowerIndex - i);
    }
    return minLength != std::numeric_limits<int>::max() ? minLength : 0;
  }
};