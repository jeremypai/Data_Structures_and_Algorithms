#ifndef KRUSKAL_ALGORITHM_H_
#define KRUSKAL_ALGORITHM_H_

#include <algorithm>
#include <vector>

struct MSTEdge {
  int src;
  int dest;
  int weight;
};

class KruskalMST {
 private:
  std::vector<MSTEdge> edgeList_;
  std::vector<bool> inMST_;

 public:
  KruskalMST(int v) : inMST_(v, false) {}
  ~KruskalMST() = default;

  void addEdge(int u, int v, int w) {
    MSTEdge edge = {u, v, w};
    edgeList_.emplace_back(edge);
  }

  std::vector<MSTEdge> kruskalMST() {
    // Sort edges in non-decreasing order of weight
    std::sort(edgeList_.begin(), edgeList_.end(),
              [](MSTEdge x, MSTEdge y) { return x.weight < y.weight; });

    std::vector<MSTEdge> ans;
    for (const auto& edge : edgeList_) {
      const auto& src = edge.src;
      const auto& dest = edge.dest;

      if (inMST_[src] && inMST_[dest]) {
        // already into spanning tree
        continue;
      }

      inMST_[src] = true;
      inMST_[dest] = true;
      ans.emplace_back(edge);
    }

    return ans;
  }
};

#endif  // !KRUSKAL_ALGORITHM_H_