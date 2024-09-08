#include <algorithm>

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
 public:
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    diameterOfBinaryTreeRec(root, ans);
    return ans;
  }

 private:
  int diameterOfBinaryTreeRec(TreeNode *node, int &ans) {
    if (node == nullptr) {
      return 0;
    }

    int left = diameterOfBinaryTreeRec(node->left, ans);
    int right = diameterOfBinaryTreeRec(node->right, ans);
    ans = std::max(ans, left + right);

    // add an edge from the child to its parent
    return std::max(left, right) + 1;
  }
};