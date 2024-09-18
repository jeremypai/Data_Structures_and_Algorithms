#include <queue>
#include <vector>

class SolutionBellmanFord {
 public:
  int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[k - 1] = 0;
    for (int i = 0; i < n; ++i) {
      for (const auto& edge : times) {
        const auto& src = edge[0] - 1;
        const auto& dest = edge[1] - 1;
        const auto& distance = edge[2];
        if (dist[src] != std::numeric_limits<int>::max()) {
          dist[dest] = std::min(dist[dest], dist[src] + distance);
        }
      }
    }

    for (const auto& edge : times) {
      const auto& src = edge[0] - 1;
      const auto& dest = edge[1] - 1;
      const auto& distance = edge[2];
      if (dist[src] != std::numeric_limits<int>::max() &&
          dist[dest] > dist[src] + distance) {
        // negative weight cycle exist
        return -1;
      }
    }

    int maxTime = -1;
    for (const auto& d : dist) {
      if (d == std::numeric_limits<int>::max()) {
        maxTime = -1;
        break;
      }

      maxTime = std::max(maxTime, d);
    }
    return maxTime;
  }
};

class SolutionDijkstra {
 private:
  struct Path {
    int src;
    int dest;
    int distance;
  };

 public:
  int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> adjList(
        n + 1, std::vector<std::pair<int, int>>{});
    for (const auto& edge : times) {
      adjList[edge[0]].emplace_back(std::make_pair(edge[1], edge[2]));
    }

    std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
    std::vector<bool> visited(n + 1, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.push(std::make_pair(0, k));
    while (!pq.empty()) {
      std::pair<int, int> cur = pq.top();
      pq.pop();
      if (visited[cur.second]) {
        continue;
      }
      visited[cur.second] = true;
      dist[cur.second] = cur.first;
      for (const auto& neighbor : adjList[cur.second]) {
        pq.push(
            std::make_pair(dist[cur.second] + neighbor.second, neighbor.first));
      }
    }

    int maxTime = -1;
    for (int i = 1; i < dist.size(); ++i) {
      if (dist[i] == std::numeric_limits<int>::max()) {
        maxTime = -1;
        break;
      }

      maxTime = std::max(maxTime, dist[i]);
    }
    return maxTime;
  }
};