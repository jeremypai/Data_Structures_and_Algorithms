#include <algorithm>
#include <vector>

// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionTwoPointers {
 public:
  int maxArea(std::vector<int>& height) {
    int maxValue = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      int curHeight = std::min(height[left], height[right]);
      int curValue = curHeight * (right - left);
      maxValue = std::max(maxValue, curValue);

      if (height[left] >= height[right]) {
        --right;
      } else {
        ++left;
      }
    }
    return maxValue;
  }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class SolutionBruteForce {
 public:
  int maxArea(std::vector<int>& height) {
    int maxValue = 0;
    for (int i = 0; i < height.size() - 1; ++i) {
      for (int j = i + 1; j < height.size(); ++j) {
        int curHeight = std::min(height[i], height[j]);
        int curValue = curHeight * (j - i);
        if (curValue > maxValue) {
          maxValue = curValue;
        }
      }
    }
    return maxValue;
  }
};