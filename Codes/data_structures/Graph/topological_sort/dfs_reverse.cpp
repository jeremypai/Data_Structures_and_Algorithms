#include "dfs_reverse.h"

#include <iostream>
#include <stack>
#include <vector>

void TopologicalSortDfsReverse::topologicalSort(
    const std::vector<std::vector<int>> &v) {
  visited_ = std::vector<int>(v.size(), 0);

  for (int i = 0; i < v.size(); ++i) {
    if (visited_[i] == 0) {
      dfs(i, v);
    }
  }

  if (cycle_) {
    std::cout << "Cycle!" << std::endl;
    return;
  }

  std::cout << "DFS + Reverse: ";
  while (true) {
    if (s_.empty()) {
      break;
    }

    int vertex = s_.top();
    s_.pop();
    std::cout << vertex << " ";
  }
  std::cout << std::endl;
}

void TopologicalSortDfsReverse::dfs(int vertex,
                                    const std::vector<std::vector<int>> &v) {
  if (visited_[vertex] == 1) {
    // visit again when dfs process
    cycle_ = true;
    return;
  }

  if (visited_[vertex] == 2) {
    // already visited
    return;
  }

  visited_[vertex] = 1;
  for (const auto neighbor : v[vertex]) {
    dfs(neighbor, v);
  }
  visited_[vertex] = 2;
  s_.push(vertex);
}