#include "insertion_sort.h"

void swap(int array[], int index1, int index2) {
  int tmp = array[index1];
  array[index1] = array[index2];
  array[index2] = tmp;
}

void insertionSort(int array[], int size) {
  if (array == nullptr) {
    return;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (array[j] > array[j + 1]) {
        swap(array, j, j + 1);
      } else {
        // REMARK more efficient than bubble sort
        break;
      }
    }
  }
}