#include <iostream>
#include <string>

#include "bellman_ford_algorithm.h"

int main(int argc, char *argv[]) {
  int vertexNum = 5;
  BellmanFord g(vertexNum);

  g.addEdge(0, 0, 0);
  g.addEdge(0, 4, -5);

  g.addEdge(1, 1, 0);
  g.addEdge(1, 0, 5);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 2, 3);
  g.addEdge(1, 3, 9);

  g.addEdge(2, 2, 0);
  g.addEdge(2, 3, 1);

  g.addEdge(3, 3, 0);

  g.addEdge(4, 4, 0);
  g.addEdge(4, 3, 2);

  std::vector<int> shortestPaths = g.bellmanFord(1);
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