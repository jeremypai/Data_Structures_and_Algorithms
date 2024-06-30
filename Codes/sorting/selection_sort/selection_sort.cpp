#include "selection_sort.h"

void swap(int array[], int index1, int index2) {
  int tmp = array[index1];
  array[index1] = array[index2];
  array[index2] = tmp;
}

void selectionSort(int array[], int size) {
  if (array == nullptr) {
    return;
  }

  for (int i = 0; i < size; ++i) {
    int indexMin = i;
    for (int j = i + 1; j < size ; ++j) {
      if (array[indexMin] > array[j]) {
        indexMin = j;
      }
    }

    if (indexMin != i) {
      swap(array, indexMin, i);
    }
  }
}