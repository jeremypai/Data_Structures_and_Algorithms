#include "binary_tree.h"

#include <iostream>
#include <queue>
#include <string>

void dfsLeftPreOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  res = res + std::to_string(node->val) + " ";
  dfsLeftPreOrderTraversal(node->left, res);
  dfsLeftPreOrderTraversal(node->right, res);
}

void dfsLeftInOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  dfsLeftInOrderTraversal(node->left, res);
  res = res + std::to_string(node->val) + " ";
  dfsLeftInOrderTraversal(node->right, res);
}

void dfsLeftPostOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  dfsLeftPostOrderTraversal(node->left, res);
  dfsLeftPostOrderTraversal(node->right, res);
  res = res + std::to_string(node->val) + " ";
}

void dfsRightPreOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  res = res + std::to_string(node->val) + " ";
  dfsRightPreOrderTraversal(node->right, res);
  dfsRightPreOrderTraversal(node->left, res);
}

void dfsRightInOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  dfsRightInOrderTraversal(node->right, res);
  res = res + std::to_string(node->val) + " ";
  dfsRightInOrderTraversal(node->left, res);
}

void dfsRightPostOrderTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  dfsRightPostOrderTraversal(node->right, res);
  dfsRightPostOrderTraversal(node->left, res);
  res = res + std::to_string(node->val) + " ";
}

void bfsTraversal(TreeNode *node, std::string &res) {
  if (node == nullptr) {
    return;
  }

  std::queue<TreeNode *> q;
  q.push(node);

  while (!q.empty()) {
    TreeNode *curNode = q.front();
    q.pop();
    res = res + std::to_string(curNode->val) + " ";

    if (curNode->left) {
      q.push(curNode->left);
    }

    if (curNode->right) {
      q.push(curNode->right);
    }
  }
}