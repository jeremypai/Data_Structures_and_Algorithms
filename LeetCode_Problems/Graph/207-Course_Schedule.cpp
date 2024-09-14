#include <queue>
#include <vector>

class SolutionKahnsAlgorithm {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
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

    int traverseCnt = 0;
    while (!q.empty()) {
      int curCourse = q.front();
      q.pop();
      ++traverseCnt;

      for (const auto& course : adjList[curCourse]) {
        --inDegreeCounts[course];
        if (inDegreeCounts[course] == 0) {
          q.push(course);
        }
      }
    }

    return traverseCnt == numCourses;
  }
};

class SolutionDFS {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
    for (const auto& pair : prerequisites) {
      adjList[pair[1]].emplace_back(pair[0]);
    }

    std::vector<int> visited(numCourses, 0);
    bool isCycle = false;
    for (int i = 0; i < adjList.size(); ++i) {
      if (visited[i] == 0) {
        canFinishRec(i, adjList, visited, isCycle);
      }
    }

    return !isCycle;
  }

  void canFinishRec(int course, const std::vector<std::vector<int>>& adjList,
                    std::vector<int>& visited, bool& isCycle) {
    if (visited[course] == 1) {
      isCycle = true;
      return;
    }

    if (visited[course] == 2) {
      return;
    }

    visited[course] = 1;
    for (const auto& neighbor : adjList[course]) {
      canFinishRec(neighbor, adjList, visited, isCycle);
    }
    visited[course] = 2;
  }
};