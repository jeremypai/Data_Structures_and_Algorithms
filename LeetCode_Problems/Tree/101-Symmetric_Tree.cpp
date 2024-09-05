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

class SolutionRec {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isSymmetricRec(root->left, root->right);
  }

 private:
  bool isSymmetricRec(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr) {
      return true;
    }

    if (node1 && node2 == nullptr) {
      return false;
    }

    if (node1 == nullptr && node2) {
      return false;
    }

    if (node1->val != node2->val) {
      return false;
    }

    return isSymmetricRec(node1->left, node2->right) &&
           isSymmetricRec(node1->right, node2->left);
  }
};

class SolutionIter {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    std::queue<TreeNode *> q1;
    std::queue<TreeNode *> q2;
    q1.push(root->left);
    q2.push(root->right);

    while (!q1.empty() && !q2.empty()) {
      TreeNode *node1 = q1.front();
      TreeNode *node2 = q2.front();
      q1.pop();
      q2.pop();

      if (node1 == nullptr && node2 == nullptr) {
        continue;
      }

      if (node1 && node2 == nullptr) {
        return false;
      }

      if (node1 == nullptr && node2) {
        return false;
      }

      if (node1->val != node2->val) {
        return false;
      }

      q1.push(node1->left);
      q2.push(node2->right);

      q1.push(node1->right);
      q2.push(node2->left);
    }

    return q1.empty() && q2.empty();
  }
};