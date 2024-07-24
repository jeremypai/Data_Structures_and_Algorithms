#include <vector>

class Solution {
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    int maxArea = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          int area = searchIslandArea(grid, i, j);
          if (area > maxArea) {
            maxArea = area;
          }
        }
      }
    }

    return maxArea;
  }

 private:
  int searchIslandArea(std::vector<std::vector<int>> &grid, int i, int j) {
    if (grid[i][j] != 1) {
      return 0;
    }

    // already visited
    grid[i][j] = -1;

    int curIslandArea = 1;
    if (i - 1 >= 0) {
      curIslandArea += searchIslandArea(grid, i - 1, j);
    }

    if (i + 1 < grid.size()) {
      curIslandArea += searchIslandArea(grid, i + 1, j);
    }

    if (j - 1 >= 0) {
      curIslandArea += searchIslandArea(grid, i, j - 1);
    }

    if (j + 1 < grid[0].size()) {
      curIslandArea += searchIslandArea(grid, i, j + 1);
    }

    return curIslandArea;
  }
};