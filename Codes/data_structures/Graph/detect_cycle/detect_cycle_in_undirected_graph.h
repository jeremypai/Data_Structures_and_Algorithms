#ifndef DETECT_CYCLE_IN_UNDIRECTED_GRAPH_H_
#define DETECT_CYCLE_IN_UNDIRECTED_GRAPH_H_

#include <unordered_map>
#include <vector>

class UndirectedGraph {
 private:
  std::unordered_map<int, std::vector<int>> adjList_;

 public:
  UndirectedGraph() = default;
  ~UndirectedGraph() = default;

  void addEdge(int u, int v) {
    adjList_[u].emplace_back(v);
    adjList_[v].emplace_back(u);
  }

  bool hasCycle() {
    std::vector<bool> visited(adjList_.size(), false);

    for (const auto& pair : adjList_) {
      const auto& vertex = pair.first;
      // Don't recur for vertex if it is already visited
      if (!visited[vertex]) {
        if (dfs(vertex, visited, -1)) {
          // Detect cycle
          return true;
        }
      }
    }

    // Not detect cycle
    return false;
  }

 private:
  bool dfs(int vertex, std::vector<bool>& visited, int parent) {
    // Mark the current node as visited
    visited[vertex] = true;

    // Recur for all the vertices adjacent to this vertex
    for (const auto& neighbor : adjList_[vertex]) {
      // If an adjacent vertex is not visited, then recur for that adjacent
      if (!visited[neighbor]) {
        if (dfs(neighbor, visited, vertex)) {
          return true;
        }
      } else if (neighbor != parent) {
        // If an adjacent vertex is visited and is not parent of current vertex,
        // then there exists a cycle in the graph.
        return true;
      }
    }

    return false;
  }
};

#endif  // !DETECT_CYCLE_IN_UNDIRECTED_GRAPH_H_