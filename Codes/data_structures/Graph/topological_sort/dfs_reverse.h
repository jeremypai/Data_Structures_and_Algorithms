#ifndef DFS_REVERSE_H_
#define DFS_REVERSE_H_

#include <stack>
#include <vector>

// DFS + reverse
class TopologicalSortDfsReverse {
 private:
  std::stack<int> s_;
  std::vector<int> visited_;
  bool cycle_ = false;

 public:
  TopologicalSortDfsReverse() = default;
  ~TopologicalSortDfsReverse() = default;

  void topologicalSort(const std::vector<std::vector<int>> &v);

 private:
  void dfs(int vertex, const std::vector<std::vector<int>> &v);
};

#endif  // ! DFS_REVERSE_H_