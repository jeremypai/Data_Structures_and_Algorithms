#ifndef DFS_REVERSE_H_
#define DFS_REVERSE_H_

#include <iostream>
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

  std::vector<int> topologicalSort(const std::vector<std::vector<int>>& v) {
    visited_ = std::vector<int>(v.size(), 0);

    for (int i = 0; i < v.size(); ++i) {
      if (visited_[i] == 0) {
        dfs(i, v);
      }
    }

    if (cycle_) {
      std::cout << "Cycle!" << std::endl;
      return {};
    }

    std::vector<int> ans;
    while (!s_.empty()) {
      int vertex = s_.top();
      s_.pop();
      ans.emplace_back(vertex);
    }
    return ans;
  }

 private:
  void dfs(int vertex, const std::vector<std::vector<int>>& v) {
    if (visited_[vertex] == 1) {
      // visit again when dfs process
      cycle_ = true;
      return;
    }

    if (visited_[vertex] == 2) {
      // already visited
      return;
    }

    visited_[vertex] = 1;
    for (const auto& neighbor : v[vertex]) {
      dfs(neighbor, v);
    }
    visited_[vertex] = 2;
    s_.push(vertex);
  }
};

#endif  // ! DFS_REVERSE_H_