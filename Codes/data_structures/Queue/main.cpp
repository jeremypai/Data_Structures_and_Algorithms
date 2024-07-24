#include <gtest/gtest.h>

#include "Queue_Array.h"
#include "Queue_LinkedList.h"

TEST(QueueArrayTest, SimpleTest) {
  QueueArray queue(5);
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);
  queue.push(6);  // should not be pushed into the queue
  ASSERT_EQ(queue.front(), 1);
  ASSERT_EQ(queue.back(), 5);
  ASSERT_EQ(queue.size(), 5);

  queue.pop();
  queue.pop();
  ASSERT_EQ(queue.front(), 3);
  ASSERT_EQ(queue.back(), 5);
  ASSERT_EQ(queue.size(), 3);

  queue.pop();
  queue.pop();
  queue.pop();
  ASSERT_EQ(queue.front(), -1);
  ASSERT_EQ(queue.back(), -1);
  ASSERT_EQ(queue.size(), 0);
}

TEST(QueueLinkedListTest, SimpleTest) {
  QueueLinkedList queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);
  queue.push(6);
  ASSERT_EQ(queue.front(), 1);
  ASSERT_EQ(queue.back(), 6);
  ASSERT_EQ(queue.size(), 6);

  queue.pop();
  queue.pop();
  ASSERT_EQ(queue.front(), 3);
  ASSERT_EQ(queue.back(), 6);
  ASSERT_EQ(queue.size(), 4);

  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  ASSERT_EQ(queue.front(), -1);
  ASSERT_EQ(queue.back(), -1);
  ASSERT_EQ(queue.size(), 0);
}