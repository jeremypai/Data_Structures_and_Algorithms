#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
    for (int i = 0; i < prerequisites.size(); ++i) {
      int course = prerequisites[i][0];
      int pre = prerequisites[i][1];
      adjList[pre].emplace_back(course);
    }

    std::stack<int> s;
    std::vector<int> visited(numCourses, 0);
    bool isCycle = false;
    for (int i = 0; i < adjList.size(); ++i) {
      if (visited[i] == 0) {
        dfs(s, adjList, visited, i, isCycle);
      }
    }

    if (isCycle) {
      return {};
    }

    std::vector<int> ans;
    while (true) {
      if (s.empty()) {
        break;
      }

      int val = s.top();
      s.pop();
      ans.emplace_back(val);
    }

    return ans;
  }

 private:
  void dfs(std::stack<int> &s, const std::vector<std::vector<int>> &adjList,
           std::vector<int> &visited, int vertex, bool &isCycle) {
    if (visited[vertex] == 1) {
      isCycle = true;
      return;
    }

    if (visited[vertex] == 2) {
      return;
    }

    visited[vertex] = 1;
    for (const auto &neighbor : adjList[vertex]) {
      dfs(s, adjList, visited, neighbor, isCycle);
    }
    visited[vertex] = 2;
    s.push(vertex);
  }
};