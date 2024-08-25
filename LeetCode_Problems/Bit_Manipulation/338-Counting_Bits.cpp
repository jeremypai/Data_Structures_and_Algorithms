#include <vector>

// Time Complexity: O(nlogn)
class SolutionPureBitManipulate {
 public:
  std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1);
    for (int i = 0; i < ans.size(); ++i) {
      int count = 0;
      int curVal = i;
      while (curVal) {
        curVal = curVal & (curVal - 1);
        ++count;
      }
      ans[i] = count;
    }
    return ans;
  }
};

// Time Complexity: O(n)
class SolutionDp {
 public:
  std::vector<int> countBits(int n) {
    if (n == 0) {
      return std::vector<int>{0};
    }

    if (n == 1) {
      return std::vector<int>{0, 1};
    }

    std::vector<int> ans(n + 1);
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 0; i < ans.size(); ++i) {
      if (i % 2 == 1) {
        ans[i] = ans[i / 2] + 1;
      } else {
        ans[i] = ans[i / 2];
      }
    }
    return ans;
  }
};