#include "binary_tree.h"
#include <array>
#include <gtest/gtest.h>
#include <string>
#include <vcruntime.h>

class TraverseTest : public testing::Test {
private:
  std::array<int, 15> treeArray = {5,    2, 6,    1,    4,    NULL, 7,   NULL,
                                   NULL, 3, NULL, NULL, NULL, NULL, NULL};

  TreeNode *root = nullptr;

public:
  TraverseTest() = default;
  ~TraverseTest() = default;

  TreeNode *getTree() const { return root; }

protected:
  void SetUp() override { buildTree(); }

  void TearDown() override {}

private:
  void buildTree() {
    if (treeArray.size() <= 0) {
      return;
    }

    // prepare TreeNode instances first
    TreeNode **treeNodeInstance = new TreeNode *[treeArray.size()];
    for (size_t i = 0; i < treeArray.size(); ++i) {
      if (treeArray[i] == NULL) {
        continue;
      }

      treeNodeInstance[i] = new TreeNode(treeArray[i]);
    }

    // build tree
    root = treeNodeInstance[0];
    for (size_t i = 0; i < treeArray.size(); ++i) {
      if (treeArray[i] == NULL) {
        continue;
      }

      size_t leftNodeIndex = 2 * (i + 1) - 1;
      if (leftNodeIndex < treeArray.size() &&
          treeArray[leftNodeIndex] != NULL) {
        treeNodeInstance[i]->left = treeNodeInstance[leftNodeIndex];
      }
      size_t rightNodeIndex = 2 * (i + 1);
      if (rightNodeIndex < treeArray.size() &&
          treeArray[rightNodeIndex] != NULL) {
        treeNodeInstance[i]->right = treeNodeInstance[rightNodeIndex];
      }
    }
  }
};

TEST_F(TraverseTest, DFSLeftPreOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsLeftPreOrderTraversal(tree, res);
  ASSERT_EQ(res, "5 2 1 4 3 6 7 ");
}

TEST_F(TraverseTest, DFSLeftInOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsLeftInOrderTraversal(tree, res);
  ASSERT_EQ(res, "1 2 3 4 5 6 7 ");
}

TEST_F(TraverseTest, DFSLeftPostOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsLeftPostOrderTraversal(tree, res);
  ASSERT_EQ(res, "1 3 4 2 7 6 5 ");
}

TEST_F(TraverseTest, DFSRightPreOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsRightPreOrderTraversal(tree, res);
  ASSERT_EQ(res, "5 6 7 2 4 3 1 ");
}

TEST_F(TraverseTest, DFSRightInOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsRightInOrderTraversal(tree, res);
  ASSERT_EQ(res, "7 6 5 4 3 2 1 ");
}

TEST_F(TraverseTest, DFSRightPostOrderTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  dfsRightPostOrderTraversal(tree, res);
  ASSERT_EQ(res, "7 6 3 4 1 2 5 ");
}

TEST_F(TraverseTest, BFSTraversal) {
  TreeNode *tree = getTree();
  std::string res = "";
  bfsTraversal(tree, res);
  ASSERT_EQ(res, "5 2 6 1 4 7 3 ");
}