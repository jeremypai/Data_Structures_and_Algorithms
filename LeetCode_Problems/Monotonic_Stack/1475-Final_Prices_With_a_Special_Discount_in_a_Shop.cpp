#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> finalPrices(std::vector<int>& prices) {
    std::vector<int> ans(prices.size(), 0);
    std::stack<int> s;
    for (int i = prices.size() - 1; i >= 0; --i) {
      while (!s.empty() && s.top() > prices[i]) {
        s.pop();
      }

      if (s.empty()) {
        ans[i] = prices[i];
      } else {
        ans[i] = prices[i] - s.top();
      }

      s.push(prices[i]);
    }
    return ans;
  }
};