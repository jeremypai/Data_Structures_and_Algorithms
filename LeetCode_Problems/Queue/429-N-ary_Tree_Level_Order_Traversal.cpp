
#include <queue>
#include <vector>

// Definition for a Node.
class Node {
 public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node *root) {
    if (root == nullptr) {
      return {};
    }

    std::vector<std::vector<int>> result;
    std::vector<int> level;
    std::queue<Node *> q;
    q.push(root);

    // represent the end of level
    q.push(nullptr);

    while (true) {
      if (q.empty()) {
        break;
      }

      Node *ele = q.front();
      q.pop();
      if (ele == nullptr) {
        result.emplace_back(level);
        level.clear();

        if (!q.empty()) {
          // queue is not empty
          q.push(nullptr);
        }
      } else {
        level.emplace_back(ele->val);
        for (const auto node : ele->children) {
          q.push(node);
        }
      }
    }
    return result;
  }
};