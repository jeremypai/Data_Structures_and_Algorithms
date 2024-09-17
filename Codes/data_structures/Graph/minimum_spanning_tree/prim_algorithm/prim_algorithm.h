#ifndef PRIM_ALGORITHM_H_
#define PRIM_ALGORITHM_H_

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
};

class PrimMST {
 private:
  std::unordered_map<int, std::vector<Edge>> adjList_;
  std::unordered_set<int> inMST_;

 public:
  PrimMST() = default;
  ~PrimMST() = default;

  void addEdge(int u, int v, int w) {
    // from u to v
    const auto foundU = adjList_.find(u);
    if (foundU != adjList_.end()) {
      foundU->second.emplace_back(Edge{u, v, w});
    } else {
      adjList_[u] = std::vector<Edge>{Edge{u, v, w}};
    }

    // from v to u
    const auto foundV = adjList_.find(v);
    if (foundV != adjList_.end()) {
      foundV->second.emplace_back(Edge{v, u, w});
    } else {
      adjList_[v] = std::vector<Edge>{Edge{v, u, w}};
    }
  }

  std::vector<Edge> primMST(int startIndex) {
    auto compare = [](Edge x, Edge y) {
      // cause the smallest distance to appear as the top
      return x.weight > y.weight;
    };

    std::priority_queue<Edge, std::vector<Edge>, decltype(compare)> pq(compare);

    inMST_.insert(startIndex);
    for (const auto& edge : adjList_[startIndex]) {
      pq.push(edge);
    }

    std::vector<Edge> ans;
    while (!pq.empty()) {
      Edge edge = pq.top();
      pq.pop();

      if (inMST_.count(edge.dest)) {
        continue;
      }

      inMST_.insert(edge.dest);
      ans.emplace_back(edge);

      for (const auto& neighbor : adjList_[edge.dest]) {
        pq.push(neighbor);
      }
    }

    return ans;
  }
};

#endif  // !PRIM_ALGORITHM_H_