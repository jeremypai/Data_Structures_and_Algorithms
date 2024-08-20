#include <gtest/gtest.h>

#include <vector>

#include "insertion_sort.h"

TEST(InsertionSortTest, SimpleUnsortedList) {
  std::vector<int> array = {5, 2, 9, 1, 5, 6};
  std::vector<int> sortedArray = {1, 2, 5, 5, 6, 9};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(InsertionSortTest, ReverseSortedList) {
  std::vector<int> array = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(InsertionSortTest, SortedList) {
  std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(InsertionSortTest, ListWithRepeatedElements) {
  std::vector<int> array = {3, 6, 2, 8, 2, 6, 3, 8};
  std::vector<int> sortedArray = {2, 2, 3, 3, 6, 6, 8, 8};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(InsertionSortTest, SingleElementList) {
  std::vector<int> array = {1};
  std::vector<int> sortedArray = {1};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(InsertionSortTest, ListWithNegativeNumbers) {
  std::vector<int> array = {-3, -1, -7, -4, -5, -2};
  std::vector<int> sortedArray = {-7, -5, -4, -3, -2, -1};
  insertionSort(array);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}