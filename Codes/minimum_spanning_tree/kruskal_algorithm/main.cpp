#include <gtest/gtest.h>

#include <vector>

#include "kruskal_algorithm.h"

TEST(KruskalAlgorithmTest, BasicTest) {
  int vertexNum = 4;
  std::vector<Edge> edges = {
      {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

  std::vector<Edge> ans = kruskal(edges, vertexNum);
  int totalWeight = 0;
  for (const auto &edge : ans) {
    totalWeight += edge.weight;
  }
  ASSERT_EQ(totalWeight, 19);
}