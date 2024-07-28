#ifndef KRUSKAL_ALGORITHM_H_
#define KRUSKAL_ALGORITHM_H_

#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
};

std::vector<Edge> kruskal(const std::vector<Edge>& edges, int vertexNum);

#endif  // !KRUSKAL_ALGORITHM_H_