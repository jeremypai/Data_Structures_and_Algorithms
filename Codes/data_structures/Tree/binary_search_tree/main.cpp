#include <iostream>
#include "binary_search_tree.h"

int main() {
  BinarySearchTree bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  std::cout << "Inorder traversal: ";
  bst.inorderTraversal();
  std::cout << std::endl;

  std::cout << "Deleting 20" << std::endl;
  bst.deleteNode(20);
  std::cout << "Inorder traversal after deleting 20: ";
  bst.inorderTraversal();
  std::cout << std::endl;

  std::cout << "Deleting 30" << std::endl;
  bst.deleteNode(30);
  std::cout << "Inorder traversal after deleting 30: ";
  bst.inorderTraversal();
  std::cout << std::endl;

  std::cout << "Deleting 50" << std::endl;
  bst.deleteNode(50);
  std::cout << "Inorder traversal after deleting 50: ";
  bst.inorderTraversal();
  std::cout << std::endl;

  return 0;
}