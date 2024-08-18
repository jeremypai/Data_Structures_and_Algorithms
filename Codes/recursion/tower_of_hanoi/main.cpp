#include <gtest/gtest.h>

#include <stack>

#include "tower_of_hanoi.h"

TEST(TowerOfHanoiTest, OneLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, TwoLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, ThreeLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  stackFrom.push(3);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, FourLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  stackFrom.push(3);
  stackFrom.push(4);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, FiveLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  stackFrom.push(3);
  stackFrom.push(4);
  stackFrom.push(5);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, SixLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  stackFrom.push(3);
  stackFrom.push(4);
  stackFrom.push(5);
  stackFrom.push(6);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}

TEST(TowerOfHanoiTest, SevenLayer) {
  std::stack<int> stackFrom;
  std::stack<int> stackBuffer;
  std::stack<int> stackTo;
  stackFrom.push(1);
  stackFrom.push(2);
  stackFrom.push(3);
  stackFrom.push(4);
  stackFrom.push(5);
  stackFrom.push(6);
  stackFrom.push(7);
  std::stack<int> stackTest = stackFrom;

  int layer = static_cast<int>(stackFrom.size());
  moveTowers(layer, stackFrom, stackBuffer, stackTo);
  ASSERT_TRUE(stackFrom.empty());
  ASSERT_TRUE(stackBuffer.empty());
  ASSERT_FALSE(stackTo.empty());
  while (true) {
    if (stackTo.empty() && stackTest.empty()) {
      break;
    }

    int top = stackTo.top();
    int topTest = stackTest.top();
    ASSERT_EQ(top, topTest);

    stackTo.pop();
    stackTest.pop();
  }
}