#include "merge_sort.h"

#include <vcruntime.h>

void sort(int array[], int low, int mid, int high) {
  int *sortedArray = new int[high - low + 1];
  int sortedArrayIndex = 0;
  int leftIndex = low;
  int rightIndex = mid + 1;

  while (true) {
    if (leftIndex <= mid && rightIndex <= high) {
      if (array[leftIndex] <= array[rightIndex]) {
        sortedArray[sortedArrayIndex] = array[leftIndex];
        ++leftIndex;
      } else {
        sortedArray[sortedArrayIndex] = array[rightIndex];
        ++rightIndex;
      }
    } else if (leftIndex > mid && rightIndex <= high) {
      sortedArray[sortedArrayIndex] = array[rightIndex];
      ++rightIndex;
    } else if (leftIndex <= mid && rightIndex > high) {
      sortedArray[sortedArrayIndex] = array[leftIndex];
      ++leftIndex;
    } else {
      break;
    }

    ++sortedArrayIndex;
  }

  for (int i = 0; i < high - low + 1; ++i) {
    array[low + i] = sortedArray[i];
  }

  delete[] sortedArray;
}

void mergeSort(int array[], int low, int high) {
  if (array == nullptr) {
    return;
  }

  if (low >= high) {
    return;
  }

  int mid = (low + high) / 2;
  mergeSort(array, low, mid);
  mergeSort(array, mid + 1, high);
  sort(array, low, mid, high);
}