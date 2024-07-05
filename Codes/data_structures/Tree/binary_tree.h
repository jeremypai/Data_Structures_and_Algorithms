#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "gtest/gtest.h"
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void dfsLeftPreOrderTraversal(TreeNode *node, std::string &res);

void dfsLeftInOrderTraversal(TreeNode *node, std::string &res);

void dfsLeftPostOrderTraversal(TreeNode *node, std::string &res);

void dfsRightPreOrderTraversal(TreeNode *node, std::string &res);

void dfsRightInOrderTraversal(TreeNode *node, std::string &res);

void dfsRightPostOrderTraversal(TreeNode *node, std::string &res);

void bfsTraversal(TreeNode *node, std::string &res);

#endif // ! BINARY_TREE_H_