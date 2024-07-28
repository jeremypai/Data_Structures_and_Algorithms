#include <gtest/gtest.h>

#include "detect_cycle_in_directed_graph.h"
#include "detect_cycle_in_undirected_graph.h"

TEST(DirectedGraphDetectCycleTest, GraphWithACycleTest) {
  DirectedGraph g1;
  g1.addEdge(0, 1);
  g1.addEdge(1, 2);
  g1.addEdge(2, 3);
  g1.addEdge(3, 1);  // This edge creates a cycle
  ASSERT_TRUE(g1.hasCycle());
}

TEST(DirectedGraphDetectCycleTest, GraphWithoutACycleTest) {
  DirectedGraph g2;
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(2, 3);
  ASSERT_FALSE(g2.hasCycle());
}

TEST(DirectedGraphDetectCycleTest, MoreComplexGraphWithACycleTest) {
  DirectedGraph g3;
  g3.addEdge(0, 1);
  g3.addEdge(0, 2);
  g3.addEdge(1, 2);
  g3.addEdge(2, 0);  // This edge creates a cycle
  g3.addEdge(2, 3);
  g3.addEdge(3, 3);  // Self-loop
  ASSERT_TRUE(g3.hasCycle());
}

TEST(UndirectedGraphDetectCycleTest, GraphWithACycleTest) {
  UndirectedGraph g4;
  g4.addEdge(0, 1);
  g4.addEdge(1, 2);
  g4.addEdge(2, 3);
  g4.addEdge(3, 1);  // This edge creates a cycle
  ASSERT_TRUE(g4.hasCycle());
}

TEST(UndirectedGraphDetectCycleTest, GraphWithoutACycleTest) {
  UndirectedGraph g5;
  g5.addEdge(0, 1);
  g5.addEdge(1, 2);
  g5.addEdge(2, 3);
  ASSERT_FALSE(g5.hasCycle());
}

TEST(UndirectedGraphDetectCycleTest, MoreComplexGraphWithACycleTest) {
  UndirectedGraph g6;
  g6.addEdge(0, 1);
  g6.addEdge(1, 2);
  g6.addEdge(2, 3);
  g6.addEdge(3, 4);
  g6.addEdge(4, 1);  // This edge creates a cycle
  ASSERT_TRUE(g6.hasCycle());
}