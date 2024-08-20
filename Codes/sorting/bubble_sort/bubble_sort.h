#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include <vector>

inline void bubbleSort(std::vector<int>& array) {
  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < array.size() - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
      }
    }
  }
}

#endif  // !BUBBLE_SORT_H_