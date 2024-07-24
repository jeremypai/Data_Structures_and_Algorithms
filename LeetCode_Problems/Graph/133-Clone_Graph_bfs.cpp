#include <queue>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
 public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->neighbors.empty()) {
      return new Node(node->val);
    }

    std::unordered_map<Node *, Node *> hashMap;
    hashMap[node] = new Node(node->val);
    std::queue<Node *> q;
    q.push(node);
    while (true) {
      if (q.empty()) {
        break;
      }

      Node *cur = q.front();
      for (const auto neighbor : cur->neighbors) {
        const auto found = hashMap.find(neighbor);
        if (found == hashMap.end()) {
          hashMap[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        hashMap[cur]->neighbors.emplace_back(hashMap[neighbor]);
      }

      q.pop();
    }

    return hashMap[node];
  }
};