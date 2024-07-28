#ifndef KRUSKAL_ALGORITHM_H_
#define KRUSKAL_ALGORITHM_H_

#include <algorithm>
#include <vector>

#include "union_find.h"

struct Edge {
  int src;
  int dest;
  int weight;
};

inline std::vector<Edge> kruskal(const std::vector<Edge> &edges,
                                 int vertexNum) {
  std::vector<Edge> edgesCopy = edges;

  // Sort edges in non-decreasing order of weight
  std::sort(edgesCopy.begin(), edgesCopy.end(),
            [](Edge x, Edge y) { return x.weight < y.weight; });

  UnionFind uf(vertexNum);

  std::vector<Edge> ans;
  for (const auto &edge : edgesCopy) {
    const auto &src = edge.src;
    const auto &dest = edge.dest;

    if (uf.isConnected(src, dest)) {
      continue;
    }

    uf.unite(src, dest);
    ans.emplace_back(edge);
  }

  return ans;
}

#endif  // !KRUSKAL_ALGORITHM_H_