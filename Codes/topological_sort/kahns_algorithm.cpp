#include "kahns_algorithm.h"

#include <iostream>
#include <queue>
#include <vector>

void topologicalSortKahnsAlgorithm(const std::vector<std::vector<int>> &v) {
  // 1. Calculate in-degree count
  std::vector<int> inDegreeCount(v.size(), 0);
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      ++inDegreeCount[v[i][j]];
    }
  }

  // 2. find vertex with 0 in-degree count
  std::queue<int> q;
  for (int i = 0; i < inDegreeCount.size(); ++i) {
    if (inDegreeCount[i] == 0) {
      q.push(i);
    }
  }

  // 3. repeat 2. + update in-degree count
  std::cout << "Kahn's Algorithm: ";
  while (true) {
    if (q.empty()) {
      break;
    }

    int vertex = q.front();
    q.pop();
    std::cout << vertex << " ";

    for (const auto neighbor : v[vertex]) {
      --inDegreeCount[neighbor];
      if (inDegreeCount[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  std::cout << std::endl;
}
