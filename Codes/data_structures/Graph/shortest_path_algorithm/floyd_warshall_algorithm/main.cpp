#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "floyd_warshall_algorithm.h"

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> graph(
      6, std::vector<int>(6, std::numeric_limits<int>::max()));
  graph[0][0] = 0;
  graph[0][1] = 4;
  graph[0][2] = 2;

  graph[1][1] = 0;
  graph[1][0] = 4;
  graph[1][2] = 1;
  graph[1][3] = 5;

  graph[2][2] = 0;
  graph[2][0] = 2;
  graph[2][1] = 1;
  graph[2][3] = 8;
  graph[2][4] = 9;

  graph[3][3] = 0;
  graph[3][1] = 5;
  graph[3][2] = 8;
  graph[3][4] = 2;
  graph[3][5] = 6;

  graph[4][4] = 0;
  graph[4][3] = 2;
  graph[4][2] = 9;
  graph[4][5] = 5;

  graph[5][5] = 0;
  graph[5][4] = 5;
  graph[5][3] = 6;

  std::cout << "Original distance matrix: " << std::endl;
  for (int i = 0; i < graph.size(); ++i) {
    for (int j = 0; j < graph.size(); ++j) {
      std::cout << (graph[i][j] == std::numeric_limits<int>::max()
                        ? "INF"
                        : std::to_string(graph[i][j]))
                << "\t";
    }
    std::cout << std::endl;
  }

  // Floyd-Warshall algorithm
  int vertexNum = 6;
  FloydWarshall g(vertexNum);

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

  std::vector<std::vector<int>> shortestPaths = g.floydWarshall();
  std::cout << "floyd-warshall algorithm: " << std::endl;
  for (int i = 0; i < shortestPaths.size(); ++i) {
    for (int j = 0; j < shortestPaths.size(); ++j) {
      std::cout << (shortestPaths[i][j] == std::numeric_limits<int>::max()
                        ? "INF"
                        : std::to_string(shortestPaths[i][j]))
                << "\t";
    }
    std::cout << std::endl;
  }

  return 0;
}