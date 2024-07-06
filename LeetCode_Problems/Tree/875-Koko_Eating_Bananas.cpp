#include <vector>

class Solution {
private:
  int k_ = 0;

public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int maxPile = 0;
    for (const auto pile : piles) {
      if (pile > maxPile) {
        maxPile = pile;
      }
    }
    searchForMinimumK(piles, h, 1, maxPile);
    return k_;
  }

  void searchForMinimumK(const std::vector<int> &piles, int h, int start,
                         int end) {
    if (start > end) {
      return;
    }

    // use binary search to search our target K
    int curK = (start + end) / 2;

    // make curH a long type to prevent overflow
    long curH = 0;
    for (const auto pile : piles) {
      curH += pile / curK;
      if (pile % curK > 0) {
        curH += 1;
      }
    }

    if (curH <= h) {
      k_ = curK;
      searchForMinimumK(piles, h, start, curK - 1);
    } else {
      searchForMinimumK(piles, h, curK + 1, end);
    }
  }
};