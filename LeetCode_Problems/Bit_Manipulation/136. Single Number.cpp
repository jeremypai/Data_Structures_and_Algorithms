#include <vector>

// REMARK Based on the fact that two same values do XOR operation would
// eventually produce 0
class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    for (const auto num : nums) {
      ans = ans ^ num;
    }
    return ans;
  }
};