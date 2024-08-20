#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <vector>

inline void selectionSort(std::vector<int>& array) {
  for (int i = 0; i < array.size(); ++i) {
    int indexMin = i;
    for (int j = i + 1; j < array.size(); ++j) {
      if (array[indexMin] > array[j]) {
        indexMin = j;
      }
    }
    std::swap(array[indexMin], array[i]);
  }
}

#endif  // !SELECTION_SORT_H_