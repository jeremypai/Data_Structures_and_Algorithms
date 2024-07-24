#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include <vcruntime.h>

#include <stdexcept>
#include <vector>

class MaxHeap {
 private:
  std::vector<int> heap_;

 public:
  MaxHeap() = default;
  ~MaxHeap() = default;

  void insert(int value) {
    heap_.emplace_back(value);
    moveUp(heap_.size() - 1);
  }

  int deleteMax() {
    if (heap_.empty()) {
      throw std::runtime_error("Heap is empty");
    }

    int maxValue = heap_[0];
    heap_[0] = heap_[heap_.size() - 1];
    heap_.pop_back();

    moveDown(0);

    return maxValue;
  }

  int peekMax() const {
    if (heap_.empty()) {
      throw std::runtime_error("Heap is empty");
    }
    return heap_[0];
  }

  bool isEmpty() const { return heap_.empty(); }

  size_t size() const { return heap_.size(); }

 private:
  void moveUp(int index) {
    while (index > 0 && heap_[int((index - 1) / 2)] < heap_[index]) {
      std::swap(heap_[int((index - 1) / 2)], heap_[index]);
      index = int((index - 1) / 2);
    }
  }

  void moveDown(int index) {
    int curIndex = index;
    while (true) {
      int maxIndex = curIndex;
      int leftChildIndex = 2 * (curIndex + 1) - 1;
      int rightChildIndex = 2 * (curIndex + 1);

      if (leftChildIndex < heap_.size() &&
          heap_[leftChildIndex] > heap_[maxIndex]) {
        maxIndex = leftChildIndex;
      }

      if (rightChildIndex < heap_.size() &&
          heap_[rightChildIndex] > heap_[maxIndex]) {
        maxIndex = rightChildIndex;
      }

      if (maxIndex == curIndex) {
        break;
      }

      std::swap(heap_[maxIndex], heap_[curIndex]);
      curIndex = maxIndex;
    }
  }
};

#endif  // !MAX_HEAP_H_