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
  std::vector<int> result_;
  int mostCnt_ = 0;
  int curCnt_ = 0;
  int *preValue_ = nullptr;

public:
  std::vector<int> findMode(TreeNode *root) {
    if (root == nullptr) {
      return result_;
    }

    traverse(root);
    return result_;
  }

private:
  void traverse(TreeNode *node) {
    if (node == nullptr) {
      return;
    }

    traverse(node->left);

    if (preValue_ == nullptr || *preValue_ != node->val) {
      preValue_ = &(node->val);
      curCnt_ = 1;
    } else {
      ++curCnt_;
    }

    if (curCnt_ > mostCnt_) {
      result_.clear();
      result_.emplace_back(*preValue_);
      mostCnt_ = curCnt_;
    } else if (curCnt_ == mostCnt_) {
      result_.emplace_back(*preValue_);
    }

    traverse(node->right);
  }
};