#include "dijkstra_algorithm.h"

#include <limits>
#include <queue>
#include <vector>

std::vector<int> dijkstra(const std::vector<std::vector<Path>> &graph,
                          int start) {
  std::vector<int> dist(graph.size(), std::numeric_limits<int>::max());
  std::vector<bool> visited(graph.size(), false);

  // priority queue to store vertices to be processed
  auto compare = [](Path a, Path b) {
    // cause the smallest distance to appear as the top
    return a.distance > b.distance;
  };
  std::priority_queue<Path, std::vector<Path>, decltype(compare)> pq(compare);

  // add start vertex to priority queue
  pq.push(Path(start, start, 0));

  while (true) {
    if (pq.empty()) {
      break;
    }

    Path curPath = pq.top();
    pq.pop();

    if (visited[curPath.vertexTo]) {
      continue;
    }
    visited[curPath.vertexTo] = true;
    dist[curPath.vertexTo] = curPath.distance;

    for (const auto path : graph[curPath.vertexTo]) {
      const int vertexFrom = path.vertexFrom;
      const int vertexTo = path.vertexTo;
      const int distance = path.distance;
      int distanceTo = (curPath.distance + distance);
      if (!visited[vertexTo] && distanceTo < dist[vertexTo]) {
        pq.push(Path(vertexFrom, vertexTo, distanceTo));
      }
    }
  }

  return dist;
}
