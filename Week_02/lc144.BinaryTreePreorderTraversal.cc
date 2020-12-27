/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

二叉树前序遍历: 从根节点出发递归
顺序：根节点，左节点，右节点

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
  bool preorder(TreeNode* root, vector<int>& res) {
    if (root != nullptr) {
      res.push_back(root->val);
      preorder(root->left, res);
      preorder(root->right, res);
      return true;
    }
    return false;
  }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
  }
};


Solution s_; 
TEST(CodeTest1, BinaryTreePreorder)
{
  TreeNode* node1(new TreeNode(4));
  TreeNode* node2(new TreeNode(5));
  TreeNode* node3(new TreeNode(2, node1, node2));
  TreeNode* node4(new TreeNode(6));
  TreeNode* node5(new TreeNode(3, node4, nullptr));
  TreeNode* node6(new TreeNode(1, node3, node5));

  vector<int> ans = {1, 2, 4, 5, 3, 6}; 
  EXPECT_EQ(ans, s_.preorderTraversal(node6));
}


int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}             

