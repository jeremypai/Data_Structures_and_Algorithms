#ifndef DETECT_CYCLE_IN_DIRECTED_GRAPH_H_
#define DETECT_CYCLE_IN_DIRECTED_GRAPH_H_

#include <unordered_map>
#include <vector>

class DirectedGraph {
 private:
  std::unordered_map<int, std::vector<int>> adjList_;

 public:
  DirectedGraph() = default;
  ~DirectedGraph() = default;

  void addEdge(int u, int v) { adjList_[u].emplace_back(v); }

  bool hasCycle() {
    std::vector<bool> visited(adjList_.size(), false);
    std::vector<bool> recStack(adjList_.size(), false);

    for (const auto& pair : adjList_) {
      const auto& vertex = pair.first;
      if (!visited[vertex] && dfs(vertex, visited, recStack)) {
        // Detect cycle
        return true;
      }
    }

    // Not detect cycle
    return false;
  }

 private:
  bool dfs(int vertex, std::vector<bool>& visited,
           std::vector<bool>& recStack) {
    // Mark the current node as visited and part of recursion stack
    visited[vertex] = true;
    recStack[vertex] = true;

    // Recur for all the vertices adjacent to this vertex
    for (const auto& neighbor : adjList_[vertex]) {
      if (!visited[neighbor] && dfs(neighbor, visited, recStack)) {
        return true;
      } else if (recStack[neighbor]) {
        return true;
      }
    }

    // Remove the vertex from recursion stack
    recStack[vertex] = false;
    return false;
  }
};

#endif  // !DETECT_CYCLE_IN_DIRECTED_GRAPH_H_