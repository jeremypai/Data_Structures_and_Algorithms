#ifndef FLOYD_WARSHALL_ALGORITHM_H_
#define FLOYD_WARSHALL_ALGORITHM_H_

#include <algorithm>
#include <limits>
#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
  Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

class FloydWarshall {
 private:
  std::vector<Edge> edgeList_;
  int vertexNum_ = 0;

 public:
  FloydWarshall(int v) : vertexNum_(v) {}
  ~FloydWarshall() = default;

  void addEdge(int u, int v, int w) { edgeList_.emplace_back(Edge{u, v, w}); }

  std::vector<std::vector<int>> floydWarshall() {
    // Initialize distance matrix
    std::vector<std::vector<int>> dist(
        vertexNum_,
        std::vector<int>(vertexNum_, std::numeric_limits<int>::max()));

    for (const auto& edge : edgeList_) {
      const auto& src = edge.src;
      const auto& dest = edge.dest;
      const auto& weight = edge.weight;
      dist[src][dest] = weight;
    }

    for (int k = 0; k < vertexNum_; ++k) {
      for (int i = 0; i < vertexNum_; ++i) {
        for (int j = 0; j < vertexNum_; ++j) {
          // If vertex k is on the shortest path from i to j, then update the
          // value of dist[i][j]
          if (dist[i][k] != std::numeric_limits<int>::max() &&
              dist[k][j] != std::numeric_limits<int>::max()) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    return dist;
  }
};

#endif  // ! FLOYD_WARSHALL_ALGORITHM_H_