#ifndef UNION_FIND_WITH_STATES_H_
#define UNION_FIND_WITH_STATES_H_

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

#endif // ! UNION_FIND_WITH_STATES_H_