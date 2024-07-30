#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "dijkstra_algorithm.h"

int main(int argc, char *argv[]) {
  std::vector<std::vector<Path>> graph(6, std::vector<Path>{});
  graph[0].emplace_back(Path(0, 0, 0));
  graph[0].emplace_back(Path(0, 1, 4));
  graph[0].emplace_back(Path(0, 2, 2));

  graph[1].emplace_back(Path(1, 1, 0));
  graph[1].emplace_back(Path(1, 0, 4));
  graph[1].emplace_back(Path(1, 2, 1));
  graph[1].emplace_back(Path(1, 3, 5));

  graph[2].emplace_back(Path(2, 2, 0));
  graph[2].emplace_back(Path(2, 0, 2));
  graph[2].emplace_back(Path(2, 1, 1));
  graph[2].emplace_back(Path(2, 3, 8));
  graph[2].emplace_back(Path(2, 4, 9));

  graph[3].emplace_back(Path(3, 3, 0));
  graph[3].emplace_back(Path(3, 1, 5));
  graph[3].emplace_back(Path(3, 2, 8));
  graph[3].emplace_back(Path(3, 4, 2));
  graph[3].emplace_back(Path(3, 5, 6));

  graph[4].emplace_back(Path(4, 4, 0));
  graph[4].emplace_back(Path(4, 3, 2));
  graph[4].emplace_back(Path(4, 2, 9));
  graph[4].emplace_back(Path(4, 5, 5));

  graph[5].emplace_back(Path(5, 5, 0));
  graph[5].emplace_back(Path(5, 4, 5));
  graph[5].emplace_back(Path(5, 3, 6));

  std::vector<int> shortestPaths = dijkstra(graph, 0);
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