#ifndef KRUSKAL_ALGORITHM_WITH_UNION_FIND_H_
#define KRUSKAL_ALGORITHM_WITH_UNION_FIND_H_

#include <algorithm>
#include <vector>

#include "union_find.h"

struct MSTWithUnionFindEdge {
  int src;
  int dest;
  int weight;
};

class KruskalMSTWithUnionFind {
 private:
  std::vector<MSTWithUnionFindEdge> edgeList_;
  int vertexNum_ = 0;

 public:
  KruskalMSTWithUnionFind(int v) : vertexNum_(v) {}
  ~KruskalMSTWithUnionFind() = default;

  void addEdge(int u, int v, int w) {
    // u = src, v = dest, w = weight
    MSTWithUnionFindEdge edge = {u, v, w};
    edgeList_.emplace_back(edge);
  }

  std::vector<MSTWithUnionFindEdge> kruskalMST() {
    // Sort edges in non-decreasing order of weight
    std::sort(edgeList_.begin(), edgeList_.end(),
              [](MSTWithUnionFindEdge x, MSTWithUnionFindEdge y) {
                return x.weight < y.weight;
              });

    // Initialize Union-Find
    UnionFind uf(vertexNum_);

    std::vector<MSTWithUnionFindEdge> ans;
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

#endif  // !KRUSKAL_ALGORITHM_WITH_UNION_FIND_H_