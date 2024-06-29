#include <gtest/gtest.h>

void swap(int array[], int index1, int index2) {
  int tmp = array[index1];
  array[index1] = array[index2];
  array[index2] = tmp;
}

void bubbleSort(int array[], int size) {
  if (array == nullptr) {
    return;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        swap(array, j, j + 1);
      }
    }
  }
}

TEST(BubbleSortTest, SimpleUnsortedList) {
  int array[] = {5, 2, 9, 1, 5, 6};
  int sortedArray[] = {1, 2, 5, 5, 6, 9};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(BubbleSortTest, ReverseSortedList) {
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(BubbleSortTest, SortedList) {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(BubbleSortTest, ListWithRepeatedElements) {
  int array[] = {3, 6, 2, 8, 2, 6, 3, 8};
  int sortedArray[] = {2, 2, 3, 3, 6, 6, 8, 8};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(BubbleSortTest, SingleElementList) {
  int array[] = {1};
  int sortedArray[] = {1};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}

TEST(BubbleSortTest, ListWithNegativeNumbers) {
  int array[] = {-3, -1, -7, -4, -5, -2};
  int sortedArray[] = {-7, -5, -4, -3, -2, -1};
  int size = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, size);
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], sortedArray[i])
        << "value is different - array: " << array[i]
        << ", sorted array: " << sortedArray[i];
  }
}