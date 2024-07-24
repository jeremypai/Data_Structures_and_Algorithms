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

class Solution {
 private:
  std::vector<int> maxModes_;
  int prev_ = 0;
  int curCount_ = 0;
  int maxCount_ = 0;

 public:
  std::vector<int> findMode(TreeNode *root) {
    traverse(root);
    return maxModes_;
  }

 private:
  void traverse(TreeNode *node) {
    if (node == nullptr) {
      return;
    }

    traverse(node->left);

    if (node->val == prev_) {
      ++curCount_;
    } else {
      prev_ = node->val;
      curCount_ = 1;
    }

    if (curCount_ == maxCount_) {
      maxModes_.emplace_back(node->val);
    } else if (curCount_ > maxCount_) {
      maxModes_.clear();
      maxModes_.emplace_back(node->val);
      maxCount_ = curCount_;
    }

    traverse(node->right);
  }
};