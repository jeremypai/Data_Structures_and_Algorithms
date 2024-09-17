#ifndef BELLMAN_FORD_ALGORITHM_H_
#define BELLMAN_FORD_ALGORITHM_H_

#include <iostream>
#include <limits>
#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
  Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

class BellmanFord {
 private:
  std::vector<Edge> edgeList_;
  int vertexNum_ = 0;

 public:
  BellmanFord(int v) : vertexNum_(v) {}
  ~BellmanFord() = default;

  void addEdge(int u, int v, int w) {
    edgeList_.emplace_back(Edge{u, v, w});
  }

  std::vector<int> bellmanFord(int start) {
    std::vector<int> dist(vertexNum_, std::numeric_limits<int>::max());

    // Distance to start vertex is 0
    dist[start] = 0;

    // Relax all edges vertexNum-1 times
    // This is because the longest possible path without a cycle can be
    // vertexNum-1 edges long.
    for (int i = 0; i < vertexNum_ - 1; ++i) {
      for (const auto& edge : edgeList_) {
        const int& src = edge.src;
        const int& dest = edge.dest;
        const int& weight = edge.weight;
        if (dist[src] != std::numeric_limits<int>::max()) {
          dist[dest] = std::min(dist[dest], dist[src] + weight);
        }
      }
    }

    // Check for negative-weight cycles
    // If we can still relax edges, then we have a negative cycle
    for (const auto& edge : edgeList_) {
      const int& src = edge.src;
      const int& dest = edge.dest;
      const int& weight = edge.weight;
      if (dist[src] != std::numeric_limits<int>::max() &&
          dist[src] + weight < dist[dest]) {
        std::cout << "Graph contains negative weight cycle" << std::endl;
        return {};
      }
    }

    return dist;
  }
};

#endif  // ! BELLMAN_FORD_ALGORITHM_H_