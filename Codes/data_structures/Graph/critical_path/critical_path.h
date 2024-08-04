#ifndef CRITICAL_PATH_H_
#define CRITICAL_PATH_H_

#include <algorithm>
#include <vector>

struct Task {
  int id;
  std::vector<int> dependencies;
  int duration;
  int earliestStart = 0;
  int earliestFinish = 0;
  int latestStart = 0;
  int latestFinish = 0;
};

inline std::vector<int> findCriticalPath(std::vector<Task>& tasks) {
  // Forward pass
  for (int i = 0; i < tasks.size(); ++i) {
    for (const auto& dep : tasks[i].dependencies) {
      tasks[i].earliestStart =
          std::max(tasks[i].earliestStart, tasks[dep].earliestFinish);
    }
    tasks[i].earliestFinish = tasks[i].earliestStart + tasks[i].duration;
  }

  // Backward pass
  for (auto& task : tasks) {
    task.latestStart = tasks.back().earliestFinish;
    task.latestFinish = tasks.back().earliestFinish;
  }

  for (int i = tasks.size() - 1; i >= 0; --i) {
    tasks[i].latestStart = tasks[i].latestFinish - tasks[i].duration;
    for (const auto& dep : tasks[i].dependencies) {
      tasks[dep].latestFinish =
          std::min(tasks[dep].latestFinish, tasks[i].latestStart);
    }
  }

  // Identify critical path
  std::vector<int> ans;
  for (const auto& task : tasks) {
    if (task.earliestStart == task.latestStart) {
      ans.emplace_back(task.id);
    }
  }
  return ans;
}

#endif  // !CRITICAL_PATH_H_