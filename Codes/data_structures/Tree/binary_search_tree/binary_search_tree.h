#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class BinarySearchTree {
 private:
  TreeNode* root = nullptr;

 public:
  BinarySearchTree() = default;
  ~BinarySearchTree() = default;

  void insert(int value) { root = insertRec(root, value); }

  bool search(int value) { return searchRec(root, value) != nullptr; }

  void deleteNode(int value) { root = deleteNodeRec(root, value); }

  void inorderTraversal() { inorderTraversalRec(root); }

 private:
  TreeNode* insertRec(TreeNode* node, int value) {
    if (node == nullptr) {
      return new TreeNode(value);
    }

    if (node->val > value) {
      node->left = insertRec(node->left, value);
    } else if (node->val < value) {
      node->right = insertRec(node->right, value);
    }

    return node;
  }

  TreeNode* searchRec(TreeNode* node, int value) {
    if (node == nullptr || node->val == value) {
      return node;
    }

    if (node->val > value) {
      return searchRec(node->left, value);
    }

    return searchRec(node->right, value);
  }

  TreeNode* deleteNodeRec(TreeNode* node, int value) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->val == value) {
      if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      }

      // Node with two children
      TreeNode* temp = findMin(node->right);
      node->val = temp->val;
      node->right = deleteNodeRec(node->right, temp->val);
    } else if (node->val > value) {
      node->left = deleteNodeRec(node->left, value);
    } else {
      node->right = deleteNodeRec(node->right, value);
    }

    return node;
  }

  TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void inorderTraversalRec(TreeNode* node) {
    if (node == nullptr) {
      return;
    }

    inorderTraversalRec(node->left);
    std::cout << node->val << " ";
    inorderTraversalRec(node->right);
  }
};

#endif  // !BINARY_SEARCH_TREE_H_