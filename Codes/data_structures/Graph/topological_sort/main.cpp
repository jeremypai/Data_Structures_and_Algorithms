#include <gtest/gtest.h>

#include <vector>

#include "dfs_reverse.h"
#include "kahns_algorithm.h"

std::vector<std::vector<int>> createGraph() {
  std::vector<std::vector<int>> g(6, std::vector<int>{});
  g[0].emplace_back(1);
  g[0].emplace_back(2);
  g[1].emplace_back(4);
  g[3].emplace_back(2);
  g[3].emplace_back(4);
  g[3].emplace_back(5);
  g[5].emplace_back(4);
  return g;
}

TEST(KahnsAlgorithmTest, SimpleTest) {
  std::vector<std::vector<int>> g = createGraph();

  // Kahn's Algorithm
  std::vector<int> ansKahns = topologicalSortKahnsAlgorithm(g);
  std::vector<int> ansGT = {0, 3, 1, 2, 5, 4};
  for (int i = 0; i < ansGT.size(); ++i) {
    ASSERT_EQ(ansKahns[i], ansGT[i]);
  }
}

TEST(DFSWithReverseTest, SimpleTest) {
  std::vector<std::vector<int>> g = createGraph();

  // DFS + reverse
  TopologicalSortDfsReverse c = TopologicalSortDfsReverse();
  std::vector<int> ansDFS = c.topologicalSort(g);
  std::vector<int> ansGT = {3, 5, 0, 2, 1, 4};
  for (int i = 0; i < ansGT.size(); ++i) {
    ASSERT_EQ(ansDFS[i], ansGT[i]);
  }
}