/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

二叉树中序遍历: 按照访问左子树 -> 根节点 -> 右子树的顺序
*/
#include <gtest/gtest.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool inorder(TreeNode* root, vector<int>& res) {
    if (root != nullptr) {
      inorder(root->left, res);
      res.push_back(root->val);
      inorder(root->right, res);
      return true;
    }
    return false;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }
};


Solution s_; 
TEST(CodeTest1, TreePreorder)
{
  TreeNode* node1(new TreeNode(4));
  TreeNode* node2(new TreeNode(5));
  TreeNode* node3(new TreeNode(2, node1, node2));
  TreeNode* node4(new TreeNode(6));
  TreeNode* node5(new TreeNode(3, node4, nullptr));
  TreeNode* node6(new TreeNode(1, node3, node5));

  vector<int> ans = {4, 2, 5, 1, 6, 3};
  EXPECT_EQ(ans, s_.inorderTraversal(node6));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}             

