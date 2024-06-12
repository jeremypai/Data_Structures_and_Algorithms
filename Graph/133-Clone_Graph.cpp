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
  std::unordered_map<int, Node *> hashMap;

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
  Node *dfs(Node *curNode) {
    Node *result = new Node(curNode->val);
    hashMap[curNode->val] = result;
    for (const auto neighbor : curNode->neighbors) {
      const auto found = hashMap.find(neighbor->val);
      if (found != hashMap.end()) {
        // already visited
        result->neighbors.emplace_back(found->second);
      } else {
        result->neighbors.emplace_back(dfs(neighbor));
      }
    }
    return result;
  }
};