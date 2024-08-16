// Boyer-Moore Majority Voting Algorithm
// The intuition behind the Moore's Voting Algorithm is based on the fact that
// if there is a majority element in an array, it will always remain in the
// lead, even after encountering other elements.

// Algorithm:
// 1. Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value. 
// 2. Iterate through the array nums:
//    a. If count is 0, assign the current element as the new candidate and increment count by 1.
//    b. If the current element is the same as the candidate, increment count by 1.
//    c. If the current element is different from the candidate, decrement count by 1.
// 3. After the iteration, the candidate variable will hold the majority element.

#include <vector>

class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    int candidate = 0;
    int count = 0;
    for (const auto& num : nums) {
      if (count == 0) {
        candidate = num;
      }

      if (candidate == num) {
        ++count;
      } else {
        --count;
      }
    }
    return candidate;
  }
};