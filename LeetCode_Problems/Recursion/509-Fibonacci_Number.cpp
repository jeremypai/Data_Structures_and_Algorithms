#include <unordered_map>

// Time Complexity: O(2^n)
// Space Complexity: O(n)
class SolutionRec {
 public:
  int fib(int n) {
    if (n <= 1) {
      return n;
    }
    return fib(n - 1) + fib(n - 2);
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionHashMap {
 public:
  int fib(int n) {
    std::unordered_map<int, int> hashMap;
    hashMap[0] = 0;
    hashMap[1] = 1;
    for (int i = 2; i <= n; ++i) {
      hashMap[i] = hashMap[i - 1] + hashMap[i - 2];
    }
    return hashMap[n];
  }
};