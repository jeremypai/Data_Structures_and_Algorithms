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

class SolutionRec {
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    if (root->val < val) {
      root->right = insertIntoBST(root->right, val);
    } else {
      root->left = insertIntoBST(root->left, val);
    }

    return root;
  }
};

class SolutionIter {
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    TreeNode *cur = root;
    while (true) {
      if (cur->val < val) {
        if (cur->right) {
          cur = cur->right;
        } else {
          cur->right = new TreeNode(val);
          break;
        }
      } else {
        if (cur->left) {
          cur = cur->left;
        } else {
          cur->left = new TreeNode(val);
          break;
        }
      }
    }

    return root;
  }
};