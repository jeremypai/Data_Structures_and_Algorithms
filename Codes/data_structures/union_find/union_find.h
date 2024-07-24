#ifndef UNION_FIND_H_
#define UNION_FIND_H_

#include <vector>

class UnionFind {
 private:
  // store parent nodes
  std::vector<int> parent;

  // store tree heights
  std::vector<int> rank;

 public:
  UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    // path compression: recursively sets each node's parent to the root
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

    // union by rank: merges trees based on their ranks to keep them balanced
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else {
      // rank[rootX] == rank[rootY]
      parent[rootX] = rootY;
      ++rootY;
    }
  }

  bool isConnected(int x, int y) { return find(x) == find(y); }
};

#endif  // !UNION_FIND_H_