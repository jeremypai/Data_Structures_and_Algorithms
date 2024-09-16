#include <vector>

/**
 * @brief Solution 1: Union Find
 * @note Time Complexity: O(n^2 * logn)
 * @note Space Complexity: O(n)
 */
class UnionFind {
 private:
  std::vector<int> parent;
  std::vector<int> rank;

 public:
  UnionFind(int size) : parent(size), rank(size, 0) {
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  ~UnionFind() = default;

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

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else if (rank[rootY] < rank[rootX]) {
      parent[rootY] = rootX;
    } else {
      parent[rootX] = rootY;
      ++rank[rootY];
    }
  }

  int calNumberOfConnectedComponents() const {
    int count = 0;
    for (int i = 0; i < parent.size(); ++i) {
      if (parent[i] == i) {
        ++count;
      }
    }
    return count;
  }
};

class SolutionUnionFind {
 public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    UnionFind uf(isConnected.size());
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = i; j < isConnected[0].size(); ++j) {
        if (isConnected[i][j] == 1) {
          uf.unite(i, j);
        }
      }
    }
    return uf.calNumberOfConnectedComponents();
  }
};

/**
 * @brief Solution 2: DFS or BFS
 * @note Time Complexity: O(V + E)
 * @note Space Complexity: O(V + E)
 */
class Solution {
 public:
  int findCircleNum(std::vector<std::vector<int>>& isConnected) {
    std::vector<std::vector<int>> adjList(isConnected.size(),
                                          std::vector<int>{});
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = 0; j < isConnected[0].size(); ++j) {
        if (isConnected[i][j] == 1) {
          adjList[i].emplace_back(j);
          adjList[j].emplace_back(i);
        }
      }
    }

    std::vector<bool> visited(isConnected.size(), false);
    std::vector<int> predecessor(isConnected.size(), -1);
    for (int i = 0; i < isConnected.size(); ++i) {
      if (!visited[i]) {
        dfs(i, adjList, visited, predecessor);
      }
    }

    int count = 0;
    for (const auto& p : predecessor) {
      if (p == -1) {
        ++count;
      }
    }
    return count;
  }

 private:
  void dfs(int index, const std::vector<std::vector<int>>& adjList,
           std::vector<bool>& visited, std::vector<int>& predecessor) {
    if (visited[index]) {
      return;
    }

    visited[index] = true;

    for (const auto& neighbor : adjList[index]) {
      if (visited[neighbor]) {
        continue;
      }

      predecessor[neighbor] = index;
      dfs(neighbor, adjList, visited, predecessor);
    }
  }
};