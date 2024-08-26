#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<char> hashSetRow[9];
    std::unordered_set<char> hashSetCol[9];
    std::unordered_set<char> hashSetSubBox[9];
    for (int i = 0; i < board[0].size(); ++i) {
      for (int j = 0; j < board.size(); ++j) {
        if (board[i][j] == '.') {
          continue;
        }

        char curVal = board[i][j];

        // check row
        if (hashSetRow[i].find(curVal) != hashSetRow[i].end()) {
          return false;
        }
        hashSetRow[i].insert(curVal);

        // check column
        if (hashSetCol[j].find(curVal) != hashSetCol[j].end()) {
          return false;
        }
        hashSetCol[j].insert(curVal);

        // check 3 x 3 sub box
        int boxIndex = (i / 3) * 3 + j / 3;
        if (hashSetSubBox[boxIndex].find(curVal) !=
            hashSetSubBox[boxIndex].end()) {
          return false;
        }
        hashSetSubBox[boxIndex].insert(curVal);
      }
    }

    return true;
  }
};