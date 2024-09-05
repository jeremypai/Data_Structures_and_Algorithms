#include <unordered_map>
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

class Solution {
 private:
  std::unordered_map<int, int> hashMap_;

 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      hashMap_[inorder[i]] = i;
    }
    return buildTreeRec(preorder, inorder, 0, preorder.size() - 1, 0,
                        inorder.size() - 1);
  }

 private:
  TreeNode* buildTreeRec(const std::vector<int>& preorder,
                         const std::vector<int>& inorder, int preorderBegin,
                         int preorderEnd, int inorderBegin, int inorderEnd) {
    if (preorderBegin > preorderEnd || inorderBegin > inorderEnd) {
      return nullptr;
    }

    int curValue = preorder[preorderBegin];
    TreeNode* curNode = new TreeNode(curValue);
    int curValueIndex = hashMap_[curValue];
    int leftSubTreeSize = curValueIndex - inorderBegin;
    curNode->left = buildTreeRec(preorder, inorder, preorderBegin + 1,
                                 preorderBegin + leftSubTreeSize, inorderBegin,
                                 curValueIndex - 1);
    curNode->right =
        buildTreeRec(preorder, inorder, preorderBegin + leftSubTreeSize + 1,
                     preorderEnd, curValueIndex + 1, inorderEnd);
    return curNode;
  }
};