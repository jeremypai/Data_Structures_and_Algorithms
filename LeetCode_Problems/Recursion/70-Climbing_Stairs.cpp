#include <unordered_map>
#include <vector>

// Time Limit Exceeded
class SolutionRec {
 public:
  int climbStairs(int n) {
    if (n <= 3) {
      return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

class SolutionHashMap {
 public:
  int climbStairs(int n) {
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < 3; ++i) {
      hashMap[i] = i;
    }

    for (int i = 3; i <= n; ++i) {
      hashMap[i] = hashMap[i - 1] + hashMap[i - 2];
    }

    return hashMap[n];
  }
};

class SolutionVector {
 public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }

    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};