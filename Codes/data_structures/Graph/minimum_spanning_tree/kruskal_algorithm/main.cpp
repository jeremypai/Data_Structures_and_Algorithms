#include <gtest/gtest.h>

#include <vector>

#include "kruskal_algorithm.h"
#include "kruskal_algorithm_with_union_find.h"

TEST(MSTKruskalAlgorithmTest, SimpleTest) {
  int vertexNum = 4;
  KruskalMST g(vertexNum);
  g.addEdge(0, 1, 10);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);

  std::vector<MSTEdge> ans = g.kruskalMST();
  int totalWeight = 0;
  for (const auto& edge : ans) {
    totalWeight += edge.weight;
  }
  ASSERT_EQ(totalWeight, 19);
}

TEST(MSTKruskalAlgorithmWithUnionFindTest, SimpleTest) {
  int vertexNum = 4;
  KruskalMSTWithUnionFind g(vertexNum);
  g.addEdge(0, 1, 10);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);

  std::vector<MSTWithUnionFindEdge> ans = g.kruskalMST();
  int totalWeight = 0;
  for (const auto& edge : ans) {
    totalWeight += edge.weight;
  }
  ASSERT_EQ(totalWeight, 19);
}