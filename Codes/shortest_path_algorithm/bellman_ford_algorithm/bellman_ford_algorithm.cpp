#include "bellman_ford_algorithm.h"
#include <iostream>
#include <limits>
#include <vector>

std::vector<int> bellmanFord(const std::vector<Edge> &edges, int vertexNum,
                             int start) {
  std::vector<int> dist(vertexNum, std::numeric_limits<int>::max());

  // Distance to start vertex is 0
  dist[start] = 0;

  // Relax all edges vertexNum-1 times
  // This is because the longest possible path without a cycle can be
  // vertexNum-1 edges long.
  for (int i = 1; i <= vertexNum - 1; ++i) {
    for (const auto edge : edges) {
      const int src = edge.src;
      const int dest = edge.dest;
      const int weight = edge.weight;
      if (dist[src] != std::numeric_limits<int>::max() &&
          dist[src] + weight < dist[dest]) {
        dist[dest] = dist[src] + weight;
      }
    }
  }

  // Check for negative-weight cycles
  // If we can still relax edges, then we have a negative cycle
  for (const auto edge : edges) {
    const int src = edge.src;
    const int dest = edge.dest;
    const int weight = edge.weight;
    if (dist[src] != std::numeric_limits<int>::max() &&
        dist[src] + weight < dist[dest]) {
      std::cout << "Graph contains negative weight cycle" << std::endl;
      return {};
    }
  }

  return dist;
}