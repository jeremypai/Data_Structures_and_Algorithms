#include "quick_sort.h"

void swap(int array[], int index1, int index2) {
  int tmp = array[index1];
  array[index1] = array[index2];
  array[index2] = tmp;
}

int sort(int array[], int low, int high) {
  int pivot = high;

  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (array[j] < array[pivot]) {
      ++i;
      swap(array, i, j);
    }
  }

  swap(array, i + 1, pivot);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (array == nullptr) {
    return;
  }

  if (low >= high) {
    return;
  }

  int pivot = sort(array, low, high);

  quickSort(array, low, pivot - 1);
  quickSort(array, pivot + 1, high);
}