#ifndef KRUSKAL_ALGORITHM_H_
#define KRUSKAL_ALGORITHM_H_

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "union_find.h"

struct Edge {
  int src;
  int dest;
  int weight;
};

class Graph {
 private:
  std::vector<Edge> edgeList_;
  int vertexNum_ = 0;

 public:
  Graph(int v) : vertexNum_(v) {}
  ~Graph() = default;

  void addEdge(int u, int v, int w) {
    // u = src, v = dest, w = weight
    Edge edge = {u, v, w};
    edgeList_.emplace_back(edge);
  }

  std::vector<Edge> kruskalMST() {
    // Sort edges in non-decreasing order of weight
    std::sort(edgeList_.begin(), edgeList_.end(),
              [](Edge x, Edge y) { return x.weight < y.weight; });

    // Initialize Union-Find
    UnionFind uf(vertexNum_);

    std::vector<Edge> ans;
    for (const auto& edge : edgeList_) {
      const auto& src = edge.src;
      const auto& dest = edge.dest;

      if (uf.isConnected(src, dest)) {
        continue;
      }

      uf.unite(src, dest);
      ans.emplace_back(edge);
    }

    return ans;
  }
};

#endif  // !KRUSKAL_ALGORITHM_H_