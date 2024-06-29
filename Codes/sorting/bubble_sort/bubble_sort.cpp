#include "bubble_sort.h"

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