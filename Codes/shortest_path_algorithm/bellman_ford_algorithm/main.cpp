#include "bellman_ford_algorithm.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::vector<Edge> edges;
  edges.emplace_back(Edge(0, 0, 0));
  edges.emplace_back(Edge(0, 4, -5));

  edges.emplace_back(Edge(1, 1, 0));
  edges.emplace_back(Edge(1, 0, 5));
  edges.emplace_back(Edge(1, 2, 2));
  edges.emplace_back(Edge(1, 2, 3));
  edges.emplace_back(Edge(1, 3, 9));

  edges.emplace_back(Edge(2, 2, 0));
  edges.emplace_back(Edge(2, 3, 1));

  edges.emplace_back(Edge(3, 3, 0));

  edges.emplace_back(Edge(4, 4, 0));
  edges.emplace_back(Edge(4, 3, 2));

  int start = 1;
  int vertexNum = 5;

  std::vector<int> shortestPaths = bellmanFord(edges, vertexNum, start);
  if (!shortestPaths.empty()) {
    std::cout << "bellman-ford algorithm: " << std::endl;
    for (int i = 0; i < shortestPaths.size(); ++i) {
      std::cout << "To vertex " << i << ": "
                << (shortestPaths[i] == std::numeric_limits<int>::max()
                        ? "INF"
                        : std::to_string(shortestPaths[i]))
                << std::endl;
    }
  }

  return 0;
}