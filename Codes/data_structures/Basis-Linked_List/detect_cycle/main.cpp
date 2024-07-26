#include <gtest/gtest.h>

#include "floyd_cycle_finding_algorithm.h"

TEST(LinkedListDetectCycleTest, NoCycle) {
  Node* test1 = new Node(1);
  test1->next = new Node(2);
  test1->next->next = new Node(3);
  ASSERT_FALSE(isLinkedListHasCycle(test1));
}

TEST(LinkedListDetectCycleTest, CycleAtTheBeginning) {
  Node* test2 = new Node(1);
  test2->next = new Node(2);
  test2->next->next = test2;
  ASSERT_TRUE(isLinkedListHasCycle(test2));
}

TEST(LinkedListDetectCycleTest, CycleAtTheMiddle) {
  Node* test3 = new Node(1);
  test3->next = new Node(2);
  test3->next->next = new Node(3);
  test3->next->next->next = test3->next;
  ASSERT_TRUE(isLinkedListHasCycle(test3));
}

TEST(LinkedListDetectCycleTest, SingleNodeNoCycle) {
  Node* test4 = new Node(1);
  ASSERT_FALSE(isLinkedListHasCycle(test4));
}

TEST(LinkedListDetectCycleTest, SingleNodeWithCycle) {
  Node* test5 = new Node(1);
  test5->next = test5;
  ASSERT_TRUE(isLinkedListHasCycle(test5));
}

TEST(LinkedListDetectCycleTest, EmptyList) {
  ASSERT_FALSE(isLinkedListHasCycle(nullptr));
}