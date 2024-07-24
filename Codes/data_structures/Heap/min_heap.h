#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <vcruntime.h>

#include <stdexcept>
#include <vector>

class MinHeap {
 private:
  std::vector<int> heap_;

 public:
  MinHeap() = default;
  ~MinHeap() = default;

  void insert(int value) {
    heap_.emplace_back(value);
    moveUp(heap_.size() - 1);
  }

  int deleteMin() {
    if (heap_.empty()) {
      throw std::runtime_error("Heap is empty");
    }

    int minValue = heap_[0];
    heap_[0] = heap_[heap_.size() - 1];
    heap_.pop_back();

    moveDown(0);

    return minValue;
  }

  int peekMin() const {
    if (heap_.empty()) {
      throw std::runtime_error("Heap is empty");
    }
    return heap_[0];
  }

  bool isEmpty() const { return heap_.empty(); }

  size_t size() const { return heap_.size(); }

 private:
  void moveUp(int index) {
    while (index > 0 && heap_[int((index - 1) / 2)] > heap_[index]) {
      std::swap(heap_[int((index - 1) / 2)], heap_[index]);
      index = int((index - 1) / 2);
    }
  }

  void moveDown(int index) {
    int curIndex = index;
    while (true) {
      int minIndex = curIndex;
      int leftChildIndex = 2 * (curIndex + 1) - 1;
      int rightChildIndex = 2 * (curIndex + 1);

      if (leftChildIndex < heap_.size() &&
          heap_[leftChildIndex] < heap_[minIndex]) {
        minIndex = leftChildIndex;
      }

      if (rightChildIndex < heap_.size() &&
          heap_[rightChildIndex] < heap_[minIndex]) {
        minIndex = rightChildIndex;
      }

      if (minIndex == curIndex) {
        break;
      }

      std::swap(heap_[minIndex], heap_[curIndex]);
      curIndex = minIndex;
    }
  }
};

#endif  // !MIN_HEAP_H_