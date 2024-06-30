#include "Stack_Array.h"
#include "Stack_LinkedList.h"
#include <gtest/gtest.h>

TEST(StackArrayTest, SimpleTest) {
  StackArray stack(5);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6); // should not be pushed into the stack
  ASSERT_EQ(stack.top(), 5);
  ASSERT_EQ(stack.size(), 5);

  stack.pop();
  stack.pop();
  ASSERT_EQ(stack.top(), 3);
  ASSERT_EQ(stack.size(), 3);
}

TEST(StackLinkedListTest, SimpleTest) {
  StackLinkedList stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  ASSERT_EQ(stack.top(), 6);
  ASSERT_EQ(stack.size(), 6);

  stack.pop();
  stack.pop();
  ASSERT_EQ(stack.top(), 4);
  ASSERT_EQ(stack.size(), 4);
}