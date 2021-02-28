/* [226][Easy] Invert Binary Tree 翻转二叉树

  Invert Binary Tree
  Invert a binary tree.

  Example:

  Input:

       4
     /   \
    2     7
   / \   / \
  1   3 6   9
  Output:

       4
     /   \
    7     2
   / \   / \
  9   6 3   1
 */
#include <gtest/gtest.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // 实现left和right的交换
  void invert(TreeNode* root) {
    if (!root) {
      return;
    }
    TreeNode* tmp = root->left;
    invert(root->left);
    invert(root->right);
    root->left = root->right;
    root->right = tmp;
  }

  TreeNode* invertTree(TreeNode* root) {
    invert(root);
    return root;
  }
};

Solution s_;
TEST(CodeTest1, InvertBinaryTree) {
  TreeNode* node1(new TreeNode(2, new TreeNode(1), new TreeNode(3)));
  TreeNode* node2(new TreeNode(7, new TreeNode(6), new TreeNode(9)));
  TreeNode* node3(new TreeNode(4, node1, node2));

  TreeNode* node4(new TreeNode(7, new TreeNode(9), new TreeNode(6)));
  TreeNode* node5(new TreeNode(2, new TreeNode(3), new TreeNode(1)));
  TreeNode* node6(new TreeNode(4, node4, node5));
  EXPECT_EQ(node6, s_.invertTree(node3)); // 过不去 new出来是不同的内存
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
