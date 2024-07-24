#include <unordered_map>
#include <vector>

class UnionFind {
 private:
  std::unordered_map<int, int> parent;
  std::unordered_map<int, int> islandAreaSet;
  int maxArea = 0;

 public:
  UnionFind() = default;
  ~UnionFind() = default;

  void add(int x) {
    const auto found = parent.find(x);
    if (found != parent.end()) {
      return;
    }
    parent[x] = x;
    islandAreaSet[x] = 1;
    maxArea = std::max(maxArea, 1);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return;
    }

    parent[rootX] = rootY;
    islandAreaSet[rootY] = islandAreaSet[rootY] + islandAreaSet[rootX];
    islandAreaSet.erase(rootX);
    maxArea = std::max(maxArea, islandAreaSet[rootY]);
  }

  bool isConnected(int x, int y) { return find(x) == find(y); }

  int getMaxArea() const { return maxArea; }
};

class Solution {
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    UnionFind uf;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          int curIndex = i * grid[0].size() + j;
          uf.add(curIndex);

          // union with left
          int leftIndex = (i - 1) * grid[0].size() + j;
          if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            if (!uf.isConnected(curIndex, leftIndex)) {
              uf.unite(curIndex, leftIndex);
            }
          }

          // union with top
          int topIndex = i * grid[0].size() + (j - 1);
          if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            if (!uf.isConnected(curIndex, topIndex)) {
              uf.unite(curIndex, topIndex);
            }
          }
        }
      }
    }

    return uf.getMaxArea();
  }
};