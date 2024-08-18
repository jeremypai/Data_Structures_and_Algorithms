#include <cmath>
#include <vector>

class Solution {
 public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    int left = 1;
    int right = std::pow(10, 9);
    while (left <= right) {
      int k = left + (right - left) / 2;
      if (canFinish(piles, h, k)) {
        right = k - 1;
      } else {
        left = k + 1;
      }
    }
    return left;
  }

 private:
  bool canFinish(const std::vector<int>& piles, int h, int k) {
    long total = 0;
    for (const auto& pile : piles) {
      total += std::ceil((double)pile / k);
    }
    return total <= h;
  }
};