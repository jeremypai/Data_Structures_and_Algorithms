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
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = nullptr;

    TreeNode *cur = root;
    while (cur->right) {
      cur = cur->right;
    }

    cur->right = temp;

    flatten(root->right);
  }
};