#include <queue>
#include <vector>

// From the problem statements, the room would be represented from 0 to n-1.
// Therefore, it would be easier to use std::vector instead of
// std::unordered_set.

class SolutionBFS {
 public:
  bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::vector<bool> visited(rooms.size(), false);
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int room = q.front();
      q.pop();

      if (visited[room]) {
        continue;
      }
      visited[room] = true;

      for (const auto& neighbor : rooms[room]) {
        q.push(neighbor);
      }
    }

    for (const auto& visit : visited) {
      if (!visit) {
        return false;
      }
    }
    return true;
  }
};

class SolutionDFS {
 public:
  bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::vector<bool> visited(rooms.size(), false);
    canVisitAllRoomsRec(rooms, visited, 0);

    for (const auto& visit : visited) {
      if (!visit) {
        return false;
      }
    }
    return true;
  }

 private:
  void canVisitAllRoomsRec(const std::vector<std::vector<int>>& rooms,
                           std::vector<bool>& visited, int room) {
    if (visited[room]) {
      return;
    }

    visited[room] = true;
    for (const auto& neighbor : rooms[room]) {
      canVisitAllRoomsRec(rooms, visited, neighbor);
    }
  }
};