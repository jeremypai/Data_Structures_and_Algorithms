#ifndef SOLLIN_ALGORITHM_H_
#define SOLLIN_ALGORITHM_H_

#include <limits>
#include <vector>

#include "union_find.h"

struct Edge {
  int src;
  int dest;
  int weight;
};

class SollinMST {
 private:
  std::vector<Edge> edgeList_;
  int vertexNum_ = 0;

 public:
  SollinMST(int v) : vertexNum_(v) {}
  ~SollinMST() = default;

  void addEdge(int u, int v, int w) {
    Edge edge = {u, v, w};
    edgeList_.emplace_back(edge);
  }

  std::vector<Edge> sollinMST() {
    UnionFind uf(vertexNum_);

    // An array to store index of the cheapest edge of subset. It store [u,v,w]
    // for each component
    std::vector<Edge> cheapest(vertexNum_,
                               {-1, -1, std::numeric_limits<int>::max()});

    // Initially there are VertexNum_ different trees.
    // Finally there will be one tree that will be MST
    int numTrees = vertexNum_;

    // Keep combining components (or sets) until all components are not combined
    // into single MST
    std::vector<Edge> ans;
    while (numTrees > 1) {
      // Traverse through all edges and update cheapest of every component
      for (const auto& edge : edgeList_) {
        // Find components (or sets) of two corners of current edge
        const int u = edge.src;
        const int v = edge.dest;
        const int w = edge.weight;

        int set1 = uf.find(u);
        int set2 = uf.find(v);

        // If two corners of current edge belong to same set, ignore current
        // edge. Else check if current edge is closer to previous cheapest edges
        // of set1 and set2
        if (set1 != set2) {
          if (cheapest[set1].weight > w) {
            cheapest[set1] = {u, v, w};
          }

          if (cheapest[set2].weight > w) {
            cheapest[set2] = {u, v, w};
          }
        }
      }

      // Consider the above picked cheapest edges and add them to MST
      for (int i = 0; i < vertexNum_; ++i) {
        // Check if cheapest for current set exists
        if (cheapest[i].weight != std::numeric_limits<int>::max()) {
          const int u = cheapest[i].src;
          const int v = cheapest[i].dest;
          const int w = cheapest[i].weight;

          int set1 = uf.find(u);
          int set2 = uf.find(v);
          if (set1 != set2) {
            ans.emplace_back(cheapest[i]);
            uf.unite(set1, set2);
            --numTrees;
          }
        }
      }

      for (int i = 0; i < vertexNum_; ++i) {
        // reset cheapest array
        cheapest[i].weight = std::numeric_limits<int>::max();
      }
    }

    return ans;
  }
};

#endif  // !SOLLIN_ALGORITHM_H_