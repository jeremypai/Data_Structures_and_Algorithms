#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::unordered_set<int> hashSet(nums1.begin(), nums1.end());
    std::unordered_set<int> ans;
    for (const auto& num : nums2) {
      if (hashSet.find(num) != hashSet.end()) {
        ans.insert(num);
      }
    }
    return std::vector<int>(ans.begin(), ans.end());
  }
};