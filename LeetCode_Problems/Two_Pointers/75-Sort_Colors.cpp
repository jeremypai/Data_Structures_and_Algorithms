#include <vector>

// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionDutchNationalFlagAlgorithm {
 public:
  void sortColors(std::vector<int>& nums) {
    int left = 0;
    int mid = 0;
    int right = nums.size() - 1;
    while (mid <= right) {
      if (nums[mid] == 0) {
        std::swap(nums[mid], nums[left]);
        ++left;
        ++mid;
      } else if (nums[mid] == 2) {
        std::swap(nums[mid], nums[right]);
        --right;
      } else {
        ++mid;
      }
    }
  }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class SolutionQuickSort {
 public:
  void sortColors(std::vector<int>& nums) {
    quicksort(nums, 0, nums.size() - 1);
  }

 private:
  void quicksort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int pivot = partition(nums, left, right);
    quicksort(nums, left, pivot - 1);
    quicksort(nums, pivot + 1, right);
  }

  int partition(std::vector<int>& nums, int left, int right) {
    int tempIndex = left + rand() % ((right - left) + 1);
    std::swap(nums[tempIndex], nums[right]);
    int pivot = nums[right];

    int i = left;
    for (int j = left; j < right; ++j) {
      if (nums[j] < pivot) {
        std::swap(nums[j], nums[i]);
        ++i;
      }
    }
    std::swap(nums[i], nums[right]);
    return i;
  }
};