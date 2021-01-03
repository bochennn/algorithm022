/* [236][Medium] Lowest Common Ancestor of a Binary Tree 二叉树的最近公共祖先
 
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."

        3
      /   \
    5       1
   / \     / \
  6   2   0   8
     / \
    7   4

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

二叉树中序遍历应用

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
  // 声明f(x) = true: 包含p或q节点
  // 节点x满足p和q的公共祖先的条件为：
  // 1. f(lson) && f(rson)
  // 2. (root == p || root == q) && (f(lson) || f(rson))

  bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return false;            
    }
    bool lson = dfs(root->left, p, q); // 从最左节点开始遍历
    bool rson = dfs(root->right, p, q);
    // 满足公共祖先条件时，记录该节点
    if ((lson && rson) || 
      ((root == p || root == q) && (lson || rson))) {
      res_ = root;
    }
      // 当有任意一个判断为true时，认为该节点包含p或q
      return (root == p || root == q) || lson || rson;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // tryout2
    if (!root || root == p || root == q) {
      return root; // 把遍历到的p和q折叠上去
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
    // dfs(root, p, q);
    // return res_;
  }

  TreeNode* res_ = nullptr;
};


Solution s_;
TEST(CodeTest1, LowestCommonAncestor) {
  TreeNode* node4(new TreeNode(2, new TreeNode(7), new TreeNode(4)));
  TreeNode* node5(new TreeNode(5, new TreeNode(6), node4));

  TreeNode* node8(new TreeNode(1, new TreeNode(0), new TreeNode(8)));
  TreeNode* node9(new TreeNode(3, node5, node8));

  EXPECT_EQ(node9, s_.lowestCommonAncestor(node9, node5, node8));
}

TEST(CodeTest2, LowestCommonAncestor) {
  TreeNode* node4(new TreeNode(2, new TreeNode(7), new TreeNode(4)));
  TreeNode* node5(new TreeNode(5, new TreeNode(6), node4));

  TreeNode* node8(new TreeNode(1, new TreeNode(0), new TreeNode(8)));
  TreeNode* node9(new TreeNode(3, node5, node8));

  EXPECT_EQ(node5, s_.lowestCommonAncestor(node9, node5, new TreeNode(4)));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
