#ifndef DIJKSTRA_ALGORITHM_H_
#define DIJKSTRA_ALGORITHM_H_

#include <limits>
#include <queue>
#include <vector>

struct Path {
  int vertexFrom;
  int vertexTo;
  int distance;
  Path(int vertexFrom, int vertexTo, int distance)
      : vertexFrom(vertexFrom), vertexTo(vertexTo), distance(distance) {}
};

inline std::vector<int> dijkstra(const std::vector<std::vector<Path>> &graph,
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

#endif  // ! DIJKSTRA_ALGORITHM_H_