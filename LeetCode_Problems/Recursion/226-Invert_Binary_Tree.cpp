#include <queue>
#include <stack>

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
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};

class SolutionIter {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *curNode = q.front();
      q.pop();
      if (!curNode) {
        continue;
      }

      TreeNode *tmp = curNode->left;
      curNode->left = curNode->right;
      curNode->right = tmp;

      q.push(curNode->left);
      q.push(curNode->right);
    }

    return root;
  }
};

class SolutionStack {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }

    std::stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *curNode = s.top();
      s.pop();
      if (!curNode) {
        continue;
      }

      TreeNode *tmp = curNode->left;
      curNode->left = curNode->right;
      curNode->right = tmp;

      s.push(curNode->left);
      s.push(curNode->right);
    }

    return root;
  }
};