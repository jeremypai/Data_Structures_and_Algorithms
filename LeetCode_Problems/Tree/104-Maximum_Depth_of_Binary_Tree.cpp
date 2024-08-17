#include <queue>
#include <utility>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class SolutionDFS {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftDepth = maxDepth(root->left) + 1;
    int rightDepth = maxDepth(root->right) + 1;

    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
  }
};

class SolutionBFS {
 public:
  int maxDepth(TreeNode *root) {
    std::queue<std::pair<TreeNode *, int>> q;
    q.push({root, 1});

    int maxDepthLen = 0;
    while (!q.empty()) {
      std::pair<TreeNode *, int> node = q.front();
      q.pop();
      if (node.first == nullptr) {
        continue;
      }

      if (node.second > maxDepthLen) {
        maxDepthLen = node.second;
      }

      q.push({node.first->left, node.second + 1});
      q.push({node.first->right, node.second + 1});
    }

    return maxDepthLen;
  }
};