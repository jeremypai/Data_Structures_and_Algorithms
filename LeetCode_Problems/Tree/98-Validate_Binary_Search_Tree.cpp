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
  bool isValidBST(TreeNode *root) { return isValidBSTInternal(root); }

private:
  bool isValidBSTInternal(TreeNode *node) {
    if (node == nullptr) {
      return true;
    }

    TreeNode *leftTreeMaxNode = getMaxNode(node->left);
    if (leftTreeMaxNode != nullptr && leftTreeMaxNode->val >= node->val) {
      return false;
    }

    TreeNode *rightTreeMinNode = getMinNode(node->right);
    if (rightTreeMinNode != nullptr && rightTreeMinNode->val <= node->val) {
      return false;
    }

    return isValidBSTInternal(node->left) && isValidBSTInternal(node->right);
  }

  TreeNode *getMaxNode(TreeNode *node) {
    if (node == nullptr) {
      return nullptr;
    }

    while (true) {
      if (node->right == nullptr) {
        break;
      }

      node = node->right;
    }

    return node;
  }

  TreeNode *getMinNode(TreeNode *node) {
    if (node == nullptr) {
      return nullptr;
    }

    while (true) {
      if (node->left == nullptr) {
        break;
      }

      node = node->left;
    }

    return node;
  }
};