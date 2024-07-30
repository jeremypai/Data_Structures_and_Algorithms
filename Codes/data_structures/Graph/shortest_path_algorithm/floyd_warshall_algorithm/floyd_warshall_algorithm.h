#ifndef FLOYD_WARSHALL_ALGORITHM_H_
#define FLOYD_WARSHALL_ALGORITHM_H_

#include <algorithm>
#include <limits>
#include <vector>

inline std::vector<std::vector<int>> floydWarshall(
    const std::vector<std::vector<int>> &graph) {
  // Initialize distance matrix
  std::vector<std::vector<int>> dist = graph;

  for (int k = 0; k < graph.size(); ++k) {
    for (int i = 0; i < graph.size(); ++i) {
      for (int j = 0; j < graph.size(); ++j) {
        // If vertex k is on the shortest path from i to j, then update the
        // value of dist[i][j]
        if (dist[i][k] != std::numeric_limits<int>::max() &&
            dist[k][j] != std::numeric_limits<int>::max()) {
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  return dist;
}

#endif  // ! FLOYD_WARSHALL_ALGORITHM_H_