#include <gtest/gtest.h>

#include <stdexcept>

#include "max_heap.h"
#include "min_heap.h"

TEST(MaxHeapTest, test) {
  MaxHeap maxHeap;

  maxHeap.insert(5);
  maxHeap.insert(3);
  maxHeap.insert(7);
  maxHeap.insert(1);
  maxHeap.insert(9);

  // Test insertion
  ASSERT_EQ(maxHeap.size(), 5);
  ASSERT_EQ(maxHeap.peekMax(), 9);

  // Test delete
  ASSERT_EQ(maxHeap.deleteMax(), 9);
  ASSERT_EQ(maxHeap.deleteMax(), 7);
  ASSERT_EQ(maxHeap.deleteMax(), 5);
  ASSERT_EQ(maxHeap.deleteMax(), 3);
  ASSERT_EQ(maxHeap.deleteMax(), 1);

  ASSERT_TRUE(maxHeap.isEmpty());

  // Test empty heap behavior
  try {
    maxHeap.deleteMax();
    ASSERT_TRUE(false);  // Should not reach here
  } catch (const std::runtime_error& e) {
    // Expected exception
  }
}

TEST(MinHeapTest, test) {
  MinHeap minHeap;

  minHeap.insert(5);
  minHeap.insert(3);
  minHeap.insert(7);
  minHeap.insert(1);
  minHeap.insert(9);

  // Test insertion
  ASSERT_EQ(minHeap.size(), 5);
  ASSERT_EQ(minHeap.peekMin(), 1);

  // Test extraction
  ASSERT_EQ(minHeap.deleteMin(), 1);
  ASSERT_EQ(minHeap.deleteMin(), 3);
  ASSERT_EQ(minHeap.deleteMin(), 5);
  ASSERT_EQ(minHeap.deleteMin(), 7);
  ASSERT_EQ(minHeap.deleteMin(), 9);

  ASSERT_TRUE(minHeap.isEmpty());

  // Test empty heap behavior
  try {
    minHeap.deleteMin();
    ASSERT_TRUE(false);  // Should not reach here
  } catch (const std::runtime_error& e) {
    // Expected exception
  }
}