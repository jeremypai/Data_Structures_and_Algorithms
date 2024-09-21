#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

#include "tries.h"

TEST(TriesTest, SimpleTest) {
  // Create am example Trie
  TrieNode* root = new TrieNode();
  std::vector<std::string> arr = {"and", "ant", "do", "geek", "dad", "ball"};
  for (const auto& s : arr) {
    insertKey(root, s);
  }

  ASSERT_TRUE(searchKey(root, {"do"}));
  ASSERT_TRUE(searchKey(root, {"geek"}));
  ASSERT_FALSE(searchKey(root, {"bat"}));
  root = deleteKey(root, "do", 0);
  ASSERT_FALSE(searchKey(root, {"do"}));
}