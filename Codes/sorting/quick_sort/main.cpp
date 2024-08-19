#include <gtest/gtest.h>

#include <vector>

#include "quick_sort.h"

TEST(QuickSortTest, SimpleUnsortedList) {
  std::vector<int> array = {5, 2, 9, 1, 5, 6};
  std::vector<int> sortedArray = {1, 2, 5, 5, 6, 9};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ReverseSortedList) {
  std::vector<int> array = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, SortedList) {
  std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ListWithRepeatedElements) {
  std::vector<int> array = {3, 6, 2, 8, 2, 6, 3, 8};
  std::vector<int> sortedArray = {2, 2, 3, 3, 6, 6, 8, 8};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, SingleElementList) {
  std::vector<int> array = {1};
  std::vector<int> sortedArray = {1};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ListWithNegativeNumbers) {
  std::vector<int> array = {-3, -1, -7, -4, -5, -2};
  std::vector<int> sortedArray = {-7, -5, -4, -3, -2, -1};
  quickSort(array, 0, array.size() - 1);
  for (int i = 0; i < array.size(); ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}