#ifndef BELLMAN_FORD_ALGORITHM_H_
#define BELLMAN_FORD_ALGORITHM_H_

#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
  Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

std::vector<int> bellmanFord(const std::vector<Edge> &edges, int vertexNum,
                             int start);

#endif  // ! BELLMAN_FORD_ALGORITHM_H_