#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
      int topOne = pq.top();
      pq.pop();
      int topTwo = pq.top();
      pq.pop();

      if (topOne != topTwo) {
        pq.push(topOne - topTwo);
      }
    }

    return !pq.empty() ? pq.top() : 0;
  }
};