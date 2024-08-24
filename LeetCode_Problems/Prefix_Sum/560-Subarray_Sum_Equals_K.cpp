#include <unordered_map>
#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    // Have a chance after we add so many numbers, we get the same prefix sum
    std::unordered_map<int, int> hashMap;
    int prefixSum = 0;
    int ans = 0;

    // If prefixSum is the same as k, we need to take this count.
    hashMap[prefixSum] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      prefixSum += nums[i];
      const auto found = hashMap.find(prefixSum - k);
      if (found != hashMap.end()) {
        ans += found->second;
      }
      ++hashMap[prefixSum];
    }

    return ans;
  }
};