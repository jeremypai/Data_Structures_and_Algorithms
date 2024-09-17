#ifndef DIJKSTRA_ALGORITHM_H_
#define DIJKSTRA_ALGORITHM_H_

#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Path {
  int from;
  int to;
  int distance;
  Path(int from, int to, int distance)
      : from(from), to(to), distance(distance) {}
};

class Dijkstra {
 private:
  std::unordered_map<int, std::vector<Path>> adjList_;
  std::unordered_set<int> visited_;

 public:
  Dijkstra() = default;
  ~Dijkstra() = default;

  void addEdge(int u, int v, int w) {
    // from u to v
    const auto foundU = adjList_.find(u);
    if (foundU != adjList_.end()) {
      foundU->second.emplace_back(Path{u, v, w});
    } else {
      adjList_[u] = std::vector<Path>{Path{u, v, w}};
    }

    // from v to u
    const auto foundV = adjList_.find(v);
    if (foundV != adjList_.end()) {
      foundV->second.emplace_back(Path{v, u, w});
    } else {
      adjList_[v] = std::vector<Path>{Path{v, u, w}};
    }
  }

  std::vector<int> dijkstra(int start) {
    // priority queue to store vertices to be processed
    auto compare = [](Path a, Path b) {
      // cause the smallest distance to appear as the top
      return a.distance > b.distance;
    };
    std::priority_queue<Path, std::vector<Path>, decltype(compare)> pq(compare);

    // add start vertex to priority queue
    pq.push(Path{start, start, 0});

    std::vector<int> dist(adjList_.size(), std::numeric_limits<int>::max());
    while (!pq.empty()) {
      Path curPath = pq.top();
      pq.pop();

      if (visited_.count(curPath.to)) {
        continue;
      }
      visited_.insert(curPath.to);
      dist[curPath.to] = curPath.distance;

      for (const auto& path : adjList_[curPath.to]) {
        const int& from = path.from;
        const int& to = path.to;
        const int& distance = path.distance;
        int distanceTo = dist[curPath.to] + distance;
        if (!visited_.count(to) && distanceTo < dist[to]) {
          pq.push(Path{from, to, distanceTo});
        }
      }
    }

    return dist;
  }
};

#endif  // ! DIJKSTRA_ALGORITHM_H_