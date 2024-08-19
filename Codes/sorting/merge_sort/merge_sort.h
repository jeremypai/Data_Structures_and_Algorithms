#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <vector>

void merge(std::vector<int>& array, int left, int mid, int right);

inline void mergeSort(std::vector<int>& array, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;
  mergeSort(array, left, mid);
  mergeSort(array, mid + 1, right);
  merge(array, left, mid, right);
}

inline void merge(std::vector<int>& array, int left, int mid, int right) {
  std::vector<int> sorted(right - left + 1, 0);
  int leftIndex = left;
  int rightIndex = mid + 1;
  int index = 0;
  while (leftIndex <= mid && rightIndex <= right) {
    if (array[leftIndex] <= array[rightIndex]) {
      sorted[index] = array[leftIndex];
      ++leftIndex;
    } else {
      sorted[index] = array[rightIndex];
      ++rightIndex;
    }
    ++index;
  }

  while (leftIndex <= mid) {
    sorted[index] = array[leftIndex];
    ++leftIndex;
    ++index;
  }

  while (rightIndex <= right) {
    sorted[index] = array[rightIndex];
    ++rightIndex;
    ++index;
  }

  for (int i = left; i <= right; ++i) {
    array[i] = sorted[i - left];
  }
}

#endif  // ! MERGE_SORT_H_