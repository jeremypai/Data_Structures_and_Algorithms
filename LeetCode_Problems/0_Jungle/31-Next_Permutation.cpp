#include <algorithm>
#include <vector>

/*
The following algorithm generates the next permutation lexicographically after a
given permutation. It changes the given permutation in-place.

1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists,
the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    int k = nums.size() - 2;
    while (k >= 0) {
      if (nums[k] < nums[k + 1]) {
        break;
      }
      --k;
    }

    if (k < 0) {
      std::reverse(nums.begin(), nums.end());
    } else {
      int l = nums.size() - 1;
      while (l > k) {
        if (nums[k] < nums[l]) {
          std::swap(nums[k], nums[l]);
          break;
        }
        --l;
      }

      std::reverse(nums.begin() + k + 1, nums.end());
    }
  }
};