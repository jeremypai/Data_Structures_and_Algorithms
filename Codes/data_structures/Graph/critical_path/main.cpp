#include <gtest/gtest.h>

#include "critical_path.h"

TEST(CriticalPathTest, Test) {
  std::vector<Task> tasks = {{0, {}, 6},     {1, {}, 4},     {2, {}, 5},
                             {3, {0}, 1},    {4, {1}, 1},    {5, {2}, 2},
                             {6, {3, 4}, 9}, {7, {3, 4}, 7}, {8, {5}, 4},
                             {9, {6}, 2},    {10, {7, 8}, 4}};

  std::vector<int> ans = findCriticalPath(tasks);
  std::vector<int> ansGT = {0, 3, 6, 7, 9, 10};
  ASSERT_EQ(ans.size(), ansGT.size());
  for (int i = 0; i < ansGT.size(); ++i) {
    ASSERT_EQ(ans[i], ansGT[i]);
  }

  ASSERT_EQ(tasks[0].earliestStart, 0);
  ASSERT_EQ(tasks[0].latestStart, 0);

  ASSERT_EQ(tasks[1].earliestStart, 0);
  ASSERT_EQ(tasks[1].latestStart, 2);

  ASSERT_EQ(tasks[2].earliestStart, 0);
  ASSERT_EQ(tasks[2].latestStart, 3);

  ASSERT_EQ(tasks[3].earliestStart, 6);
  ASSERT_EQ(tasks[3].latestStart, 6);

  ASSERT_EQ(tasks[4].earliestStart, 4);
  ASSERT_EQ(tasks[4].latestStart, 6);

  ASSERT_EQ(tasks[5].earliestStart, 5);
  ASSERT_EQ(tasks[5].latestStart, 8);

  ASSERT_EQ(tasks[6].earliestStart, 7);
  ASSERT_EQ(tasks[6].latestStart, 7);

  ASSERT_EQ(tasks[7].earliestStart, 7);
  ASSERT_EQ(tasks[7].latestStart, 7);

  ASSERT_EQ(tasks[8].earliestStart, 7);
  ASSERT_EQ(tasks[8].latestStart, 10);

  ASSERT_EQ(tasks[9].earliestStart, 16);
  ASSERT_EQ(tasks[9].latestStart, 16);

  ASSERT_EQ(tasks[10].earliestStart, 14);
  ASSERT_EQ(tasks[10].latestStart, 14);
}