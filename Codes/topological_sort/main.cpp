#include "dfs_reverse.h"
#include "kahns_algorithm.h"
#include <vector>


int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> v(6, std::vector<int>{});
  v[0].emplace_back(1);
  v[0].emplace_back(2);
  v[1].emplace_back(4);
  v[3].emplace_back(2);
  v[3].emplace_back(4);
  v[3].emplace_back(5);
  v[5].emplace_back(4);

  // Kahn's Algorithm
  topologicalSortKahnsAlgorithm(v);

  // DFS + reverse
  TopologicalSortDfsReverse c = TopologicalSortDfsReverse();
  c.topologicalSort(v);

  return 0;
}
