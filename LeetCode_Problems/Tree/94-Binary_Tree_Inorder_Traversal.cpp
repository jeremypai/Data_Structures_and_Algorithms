#include <stack>
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

class SolutionRec {
 private:
  std::vector<int> ans_;

 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    inorderTraversalRec(root);
    return ans_;
  }

 private:
  void inorderTraversalRec(TreeNode *node) {
    if (node == nullptr) {
      return;
    }

    inorderTraversalRec(node->left);
    ans_.emplace_back(node->val);
    inorderTraversalRec(node->right);
  }
};

class SolutionIter {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    std::vector<int> ans;
    std::stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur != nullptr || !s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }

      cur = s.top();
      s.pop();
      ans.emplace_back(cur->val);
      cur = cur->right;
    }

    return ans;
  }
};