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
 private:
  std::unordered_map<Node *, Node *> hashMap_;

 public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->neighbors.empty()) {
      return new Node(node->val);
    }

    return dfs(node);
  }

 private:
  Node *dfs(Node *node) {
    hashMap_[node] = new Node(node->val);
    for (const auto neighbor : node->neighbors) {
      const auto found = hashMap_.find(neighbor);
      if (found == hashMap_.end()) {
        hashMap_[node]->neighbors.emplace_back(dfs(neighbor));
      } else {
        hashMap_[node]->neighbors.emplace_back(found->second);
      }
    }

    return hashMap_[node];
  }
};