/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  bool isValidBSTInternal(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    // Check if rightmost node of root->left is valid
    TreeNode *rootLeft = root->left;
    while (true) {
      if (rootLeft == nullptr || rootLeft->right == nullptr) {
        break;
      }
      rootLeft = rootLeft->right;
    }

    if (rootLeft != nullptr && rootLeft->val >= root->val) {
      return false;
    }

    // Check if leftmost node of root->right is valid
    TreeNode *rootRight = root->right;
    while (true) {
      if (rootRight == nullptr || rootRight->left == nullptr) {
        break;
      }
      rootRight = rootRight->left;
    }

    if (rootRight != nullptr && rootRight->val <= root->val) {
      return false;
    }

    return isValidBSTInternal(root->left) && isValidBSTInternal(root->right);
  }

public:
  bool isValidBST(TreeNode *root) { return isValidBSTInternal(root); }
};