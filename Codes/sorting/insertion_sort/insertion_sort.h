#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include <vector>

inline void insertionSort(std::vector<int>& array) {
  for (int i = 0; i < array.size(); ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
      } else {
        // REMARK more efficient than bubble sort
        break;
      }
    }
  }
}

#endif  // !INSERTION_SORT_H_