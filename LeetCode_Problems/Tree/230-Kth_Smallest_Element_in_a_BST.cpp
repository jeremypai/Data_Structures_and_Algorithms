#include <vector>

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

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    kthSmallestRec(root, k, ans);
    return ans;
  }

 private:
  void kthSmallestRec(TreeNode* node, int& k, int& ans) {
    if (node == nullptr || k == 0) {
      return;
    }

    kthSmallestRec(node->left, k, ans);
    --k;
    if (k == 0) {
      ans = node->val;
    }
    kthSmallestRec(node->right, k, ans);
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionVector {
 public:
  int kthSmallest(TreeNode* root, int k) {
    std::vector<int> array;
    kthSmallestRec(root, array);
    return array[k - 1];
  }

 private:
  void kthSmallestRec(TreeNode* node, std::vector<int>& array) {
    if (node == nullptr) {
      return;
    }

    kthSmallestRec(node->left, array);
    array.emplace_back(node->val);
    kthSmallestRec(node->right, array);
  }
};