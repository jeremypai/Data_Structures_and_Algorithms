#include <climits>
#include <cmath>

class Solution {
 public:
  int divide(int dividend, int divisor) {
    // Handling corner cases
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    if (dividend == INT_MIN && divisor == 1) {
      return INT_MIN;
    }

    int ans = 0;
    long int dd = std::abs(dividend);
    long int dv = std::abs(divisor);
    while (dd >= dv) {
      long int mul = dv;
      long int count = 1;
      while (dd - mul >= mul) {
        mul += mul;
        count += count;
      }
      ans += count;
      dd -= mul;
    }

    if ((dividend > 0) ^ (divisor > 0)) {
      return -ans;
    }
    return ans;
  }
};