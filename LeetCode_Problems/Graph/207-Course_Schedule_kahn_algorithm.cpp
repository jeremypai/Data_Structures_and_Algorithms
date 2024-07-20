#include <queue>
#include <vector>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
    for (int i = 0; i < prerequisites.size(); ++i) {
      int course = prerequisites[i][0];
      int pre = prerequisites[i][1];
      adjList[pre].emplace_back(course);
    }

    std::vector<int> inDegreeCounts(numCourses, 0);
    for (int i = 0; i < adjList.size(); ++i) {
      for (int j = 0; j < adjList[i].size(); ++j) {
        ++inDegreeCounts[adjList[i][j]];
      }
    }

    std::queue<int> q;
    for (int i = 0; i < inDegreeCounts.size(); ++i) {
      if (inDegreeCounts[i] == 0) {
        // starting points
        q.push(i);
      }
    }

    int accumulate = 0;
    while (true) {
      if (q.empty()) {
        break;
      }

      int curCourse = q.front();
      q.pop();
      ++accumulate;

      for (const auto &course : adjList[curCourse]) {
        --inDegreeCounts[course];
        if (inDegreeCounts[course] == 0) {
          q.push(course);
        }
      }
    }

    if (accumulate == numCourses) {
      return true;
    }
    return false;
  }
};