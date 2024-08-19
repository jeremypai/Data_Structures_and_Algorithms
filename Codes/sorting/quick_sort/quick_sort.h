#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <cstdlib>
#include <vector>

int partition(std::vector<int>& array, int left, int right);

inline void quickSort(std::vector<int>& array, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = partition(array, left, right);
  quickSort(array, left, pivot - 1);
  quickSort(array, pivot + 1, right);
}

inline int partition(std::vector<int>& array, int left, int right) {
  // randomized choose pivot position
  int pivotIndex = rand() % (right - left + 1);
  std::swap(array[left + pivotIndex], array[right]);
  int pivot = array[right];

  int i = left;
  for (int j = left; j < right; ++j) {
    if (array[j] < pivot) {
      std::swap(array[i], array[j]);
      ++i;
    }
  }

  std::swap(array[i], array[right]);
  return i;
}

#endif  // ! QUICK_SORT_H_