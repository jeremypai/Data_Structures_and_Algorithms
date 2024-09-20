#include <stack>
#include <unordered_map>
#include <vector>

// Time Complexity: O(n+m)
// Space Complexity: O(n+m)
class SolutionMonotonicStackWithHashMap {
 public:
  std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                      std::vector<int>& nums2) {
    std::stack<int> s;
    std::unordered_map<int, int> nextGreater;
    for (int i = nums2.size() - 1; i >= 0; --i) {
      while (!s.empty() && nums2[i] > s.top()) {
        s.pop();
      }
      nextGreater[nums2[i]] = (s.empty() ? -1 : s.top());
      s.push(nums2[i]);
    }

    std::vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); ++i) {
      const auto& found = nextGreater.find(nums1[i]);
      if (found != nextGreater.end()) {
        ans[i] = found->second;
      }
    }

    return ans;
  }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
class SolutionMonotonicStack {
 public:
  std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                      std::vector<int>& nums2) {
    std::vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < ans.size(); ++i) {
      std::stack<int> s;
      for (int j = nums2.size() - 1; j >= 0; --j) {
        while (!s.empty() && nums2[j] > s.top()) {
          s.pop();
        }

        if (nums1[i] == nums2[j]) {
          ans[i] = (s.empty() ? -1 : s.top());
          break;
        }

        s.push(nums2[j]);
      }
    }
    return ans;
  }
};