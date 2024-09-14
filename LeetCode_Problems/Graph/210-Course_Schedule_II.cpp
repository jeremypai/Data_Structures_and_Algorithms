#include <queue>
#include <stack>
#include <vector>

class SolutionKahnsAlgorithm {
 public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
    std::vector<int> inDegreeCounts(numCourses, 0);
    for (const auto& pair : prerequisites) {
      adjList[pair[1]].emplace_back(pair[0]);
      ++inDegreeCounts[pair[0]];
    }

    std::queue<int> q;
    for (int i = 0; i < inDegreeCounts.size(); ++i) {
      if (inDegreeCounts[i] == 0) {
        q.push(i);
      }
    }

    std::vector<int> ans;
    while (!q.empty()) {
      int curCourse = q.front();
      q.pop();
      ans.emplace_back(curCourse);

      for (const auto& course : adjList[curCourse]) {
        --inDegreeCounts[course];
        if (inDegreeCounts[course] == 0) {
          q.push(course);
        }
      }
    }

    if (ans.size() != numCourses) {
      return {};
    }
    return ans;
  }
};

class SolutionDFS {
 public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
    for (const auto& pair : prerequisites) {
      adjList[pair[1]].emplace_back(pair[0]);
    }

    std::stack<int> s;
    std::vector<int> visited(numCourses, 0);
    bool isCycle = false;
    for (int i = 0; i < adjList.size(); ++i) {
      if (visited[i] == 0) {
        findOrderRec(i, adjList, visited, s, isCycle);
      }
    }

    if (isCycle) {
      return {};
    }

    std::vector<int> ans;
    while (!s.empty()) {
      int course = s.top();
      s.pop();
      ans.emplace_back(course);
    }
    return ans;
  }

 private:
  void findOrderRec(int course, const std::vector<std::vector<int>>& adjList,
                    std::vector<int>& visited, std::stack<int>& s,
                    bool& isCycle) {
    if (visited[course] == 1) {
      isCycle = true;
      return;
    }

    if (visited[course] == 2) {
      return;
    }

    visited[course] = 1;
    for (const auto& neighbor : adjList[course]) {
      findOrderRec(neighbor, adjList, visited, s, isCycle);
    }
    visited[course] = 2;
    s.push(course);
  }
};