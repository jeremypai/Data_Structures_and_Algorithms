#include <queue>
#include <vector>

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

class SolutionGetSize {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    std::vector<std::vector<int>> ans;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      std::vector<int> curLevel;
      int curLevelSize = q.size();
      for (int i = 0; i < curLevelSize; ++i) {
        TreeNode *curNode = q.front();
        q.pop();
        curLevel.emplace_back(curNode->val);

        if (curNode->left) {
          q.push(curNode->left);
        }

        if (curNode->right) {
          q.push(curNode->right);
        }
      }
      ans.emplace_back(curLevel);
    }
    return ans;
  }
};

class SolutionUseNullptrMarker {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    std::vector<std::vector<int>> ans;
    std::queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    std::vector<int> level;
    while (!q.empty()) {
      TreeNode *curNode = q.front();
      q.pop();

      if (curNode == nullptr) {
        ans.emplace_back(level);
        level.clear();
        if (!q.empty()) {
          q.push(nullptr);
        }
        continue;
      }

      level.emplace_back(curNode->val);
      if (curNode->left) {
        q.push(curNode->left);
      }
      if (curNode->right) {
        q.push(curNode->right);
      }
    }

    return ans;
  }
};