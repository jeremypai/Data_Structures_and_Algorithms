// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBSTRec(root, nullptr, nullptr);
  }

 private:
  bool isValidBSTRec(TreeNode* node, int* lower, int* upper) {
    if (node == nullptr) {
      return true;
    }

    if (lower && node->val <= *lower) {
      return false;
    }

    if (upper && node->val >= *upper) {
      return false;
    }

    return isValidBSTRec(node->left, lower, &node->val) &&
           isValidBSTRec(node->right, &node->val, upper);
  }
};