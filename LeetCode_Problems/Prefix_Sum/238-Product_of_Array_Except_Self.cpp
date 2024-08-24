#include <vector>

// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionPrefixSum {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> prefix(nums.size());
    std::vector<int> suffix(nums.size());
    prefix[0] = 1;
    suffix[nums.size() - 1] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
      suffix[nums.size() - i - 1] =
          suffix[nums.size() - i] * nums[nums.size() - i];
    }

    std::vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      ans[i] = prefix[i] * suffix[i];
    }

    return ans;
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n) -> But from the description of problem, we don't need
// to take output vector into calculation. Therefore, in this case, it's O(1).
class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> ans(nums.size(), 1);
    int leftProd = 1, rightProd = 1;
    for (int i = 0; i < nums.size(); ++i) {
      ans[i] *= leftProd;
      leftProd *= nums[i];
      ans[nums.size() - 1 - i] *= rightProd;
      rightProd *= nums[nums.size() - 1 - i];
    }
    return ans;
  }
};