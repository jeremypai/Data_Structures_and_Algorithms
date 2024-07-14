#ifndef DIJKSTRA_ALGORITHM_H_
#define DIJKSTRA_ALGORITHM_H_

#include <vector>

struct Path {
  int vertexFrom;
  int vertexTo;
  int distance;
  Path(int vertexFrom, int vertexTo, int distance)
      : vertexFrom(vertexFrom), vertexTo(vertexTo), distance(distance) {}
};

std::vector<int> dijkstra(const std::vector<std::vector<Path>> &graph,
                          int start);

#endif // ! DIJKSTRA_ALGORITHM_H_