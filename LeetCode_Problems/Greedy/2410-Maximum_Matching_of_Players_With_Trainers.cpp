#include <algorithm>
#include <vector>

class Solution {
 public:
  int matchPlayersAndTrainers(std::vector<int>& players,
                              std::vector<int>& trainers) {
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());
    int pIndex = 0;
    int tIndex = 0;
    while (pIndex < players.size() && tIndex < trainers.size()) {
      if (players[pIndex] <= trainers[tIndex]) {
        ++pIndex;
      }
      ++tIndex;
    }
    return pIndex;
  }
};