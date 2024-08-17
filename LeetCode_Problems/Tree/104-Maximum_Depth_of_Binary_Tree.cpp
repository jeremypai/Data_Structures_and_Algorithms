#include <queue>

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
    if (root == nullptr) {
      return 0;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      ++depth;
      int curLevelSize = q.size();
      for (int i = 0; i < curLevelSize; ++i) {
        TreeNode *curNode = q.front();
        q.pop();

        if (curNode->left) {
          q.push(curNode->left);
        }

        if (curNode->right) {
          q.push(curNode->right);
        }
      }
    }
    return depth;
  }
};