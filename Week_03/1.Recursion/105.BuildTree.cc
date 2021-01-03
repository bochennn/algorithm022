/* [105][Medium] Construct Binary Tree from Preorder and Inorder Traversal
    从前序与中序遍历序列构造二叉树

  Given preorder and inorder traversal of a tree, construct the binary tree.
 
  Note:
  You may assume that duplicates do not exist in the tree.

  For example, given

  preorder = [3,9,20,15,7]
  inorder = [9,3,15,20,7]
  Return the following binary tree:

      3
     / \
    9  20
      /  \
     15   7
  
 */
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序遍历的第一项为根节点
// 那么在中序遍历中，根节点的左子树的所有节点在根节点的左边

class Solution {
 public:
  TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                  int preorder_left, int preorder_right, 
                  int inorder_left,  int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }

    int preorder_root = preorder_left;
    // 中序遍历中的根节点index在前序遍历的left
    int inorder_root = index_[preorder[preorder_root]];

    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 左子树中的节点数目 = 根节点index - 中序left
    int size_left_subtree = inorder_root - inorder_left;
    // 这样就能再分成一个sub problem
    // 左子树以相同方式找根节点, 其根节点在left + 1上
    // 对应preorder的子树范围在[pre_left + 1, pre_left + in_left_subtree_size]
    // 对应inorder的子树范围在[in_left, in_root - 1]
    root->left = build(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    // 右子树同样是一个sub problem
    // preorder的子树范围在[pre_left + in_left_subtree_size + 1, pre_right]
    // inorder的子树范围在[in_root + 1, in_right]
    root->right = build(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    // 记录前序遍历中，每个节点值对应的位置
    for (int i = 0; i < n; i++) {
      index_[inorder[i]] = i;
    }
    return build(preorder, inorder, 0, n - 1, 0, n - 1);
  }
  unordered_map<int, int> index_;
};


Solution s_;
TEST(CodeTest1, BuildTree) {
  TreeNode* node1(new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  TreeNode* node2(new TreeNode(3, new TreeNode(9), node1));

  vector<int> preorder{3,9,20,15,7};
  vector<int> inorder{9,3,15,20,7};

  EXPECT_EQ(node2, s_.buildTree(preorder, inorder)); // 过不去
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
