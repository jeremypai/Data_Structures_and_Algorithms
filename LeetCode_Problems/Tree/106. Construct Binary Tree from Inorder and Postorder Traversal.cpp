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
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      hashMap_[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0,
                           postorder.size() - 1);
  }

 private:
  TreeNode* buildTreeHelper(const std::vector<int>& inorder,
                            const std::vector<int>& postorder, int inorderBegin,
                            int inorderEnd, int postorderBegin,
                            int postorderEnd) {
    if (inorderBegin > inorderEnd || postorderBegin > postorderEnd) {
      return nullptr;
    }

    int curNodeVal = postorder[postorderEnd];
    TreeNode* curNode = new TreeNode(curNodeVal);

    int inorderCurNodeIndex = hashMap_[curNodeVal];
    int leftTreeSize = inorderCurNodeIndex - inorderBegin;
    curNode->left = buildTreeHelper(inorder, postorder, inorderBegin,
                                    inorderCurNodeIndex - 1, postorderBegin,
                                    postorderBegin + leftTreeSize - 1);
    curNode->right =
        buildTreeHelper(inorder, postorder, inorderCurNodeIndex + 1, inorderEnd,
                        postorderBegin + leftTreeSize, postorderEnd - 1);
    return curNode;
  }
};