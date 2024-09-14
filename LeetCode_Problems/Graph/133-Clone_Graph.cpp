#include <queue>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class SolutionBFS {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    std::unordered_map<Node*, Node*> hashMap;
    std::queue<Node*> q;
    hashMap[node] = new Node(node->val);
    q.push(node);
    while (!q.empty()) {
      Node* curNode = q.front();
      q.pop();

      for (const auto& neighbor : curNode->neighbors) {
        if (hashMap.find(neighbor) == hashMap.end()) {
          hashMap[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }

        hashMap[curNode]->neighbors.emplace_back(hashMap[neighbor]);
      }
    }

    return hashMap[node];
  }
};

class SolutionDFS {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    std::unordered_map<Node*, Node*> hashMap;
    cloneGraphRec(node, hashMap);
    return hashMap[node];
  }

 private:
  void cloneGraphRec(Node* node, std::unordered_map<Node*, Node*>& hashMap) {
    hashMap[node] = new Node(node->val);
    for (const auto& neighbor : node->neighbors) {
      if (hashMap.find(neighbor) == hashMap.end()) {
        cloneGraphRec(neighbor, hashMap);
      }
      hashMap[node]->neighbors.emplace_back(hashMap[neighbor]);
    }
  }
};