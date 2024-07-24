#include <gtest/gtest.h>

#include "quick_sort.h"

TEST(QuickSortTest, SimpleUnsortedList) {
  int array[] = {5, 2, 9, 1, 5, 6};
  int sortedArray[] = {1, 2, 5, 5, 6, 9};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ReverseSortedList) {
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, SortedList) {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ListWithRepeatedElements) {
  int array[] = {3, 6, 2, 8, 2, 6, 3, 8};
  int sortedArray[] = {2, 2, 3, 3, 6, 6, 8, 8};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, SingleElementList) {
  int array[] = {1};
  int sortedArray[] = {1};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(QuickSortTest, ListWithNegativeNumbers) {
  int array[] = {-3, -1, -7, -4, -5, -2};
  int sortedArray[] = {-7, -5, -4, -3, -2, -1};
  int size = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}