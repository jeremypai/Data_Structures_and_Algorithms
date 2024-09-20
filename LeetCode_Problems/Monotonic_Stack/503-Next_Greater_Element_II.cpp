#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    std::stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i) {
      s.push(nums[i]);
    }

    std::vector<int> ans(nums.size(), -1);
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!s.empty() && nums[i] >= s.top()) {
        s.pop();
      }
      ans[i] = (s.empty() ? -1 : s.top());
      s.push(nums[i]);
    }

    return ans;
  }
};