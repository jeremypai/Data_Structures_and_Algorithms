#include <gtest/gtest.h>

#include <vector>

#include "prim_algorithm.h"

TEST(PrimAlgorithmTest, SimpleTest) {
  PrimMST g;
  g.addEdge(0, 1, 10);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);

  std::vector<Edge> ans = g.primMST(2);
  int totalWeight = 0;
  for (const auto& edge : ans) {
    totalWeight += edge.weight;
  }
  ASSERT_EQ(totalWeight, 19);
}