#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "dijkstra_algorithm.h"

int main(int argc, char *argv[]) {
  Dijkstra g;
  g.addEdge(0, 0, 0);
  g.addEdge(0, 1, 4);
  g.addEdge(0, 2, 2);

  g.addEdge(1, 1, 0);
  g.addEdge(1, 0, 4);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 5);

  g.addEdge(2, 2, 0);
  g.addEdge(2, 0, 2);
  g.addEdge(2, 1, 1);
  g.addEdge(2, 3, 8);
  g.addEdge(2, 4, 9);

  g.addEdge(3, 3, 0);
  g.addEdge(3, 1, 5);
  g.addEdge(3, 2, 8);
  g.addEdge(3, 4, 2);
  g.addEdge(3, 5, 6);

  g.addEdge(4, 4, 0);
  g.addEdge(4, 3, 2);
  g.addEdge(4, 2, 9);
  g.addEdge(4, 5, 5);

  g.addEdge(5, 5, 0);
  g.addEdge(5, 4, 5);
  g.addEdge(5, 3, 6);

  std::vector<int> shortestPaths = g.dijkstra(0);
  std::cout << "dijkstra's algorithm: " << std::endl;
  for (int i = 0; i < shortestPaths.size(); ++i) {
    std::cout << "To vertex " << i << ": "
              << (shortestPaths[i] == std::numeric_limits<int>::max()
                      ? "INF"
                      : std::to_string(shortestPaths[i]))
              << std::endl;
  }

  return 0;
}