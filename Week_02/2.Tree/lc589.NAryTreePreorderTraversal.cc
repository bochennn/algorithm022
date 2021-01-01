/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Follow up:

Recursive solution is trivial, could you do it iteratively?

N叉树前序遍历: 从根节点出发递归

*/
#include <gtest/gtest.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  bool traversal (Node* root, vector<int>& ans) {
    if (root != nullptr) {
      ans.push_back(root->val);
      for (Node* child : root->children) {
        traversal(child, ans);
      }
      return true;
    }
    return false;
  }

  vector<int> preorder(Node* root) {
    vector<int> res;
    traversal(root, res);
    return res;
  }
};


Solution s_; 
TEST(CodeTest1, TreePreorder)
{
  Node* node1(new Node(5, vector<Node*>()));
  Node* node2(new Node(6, vector<Node*>()));
  Node* node3(new Node(3, vector<Node*>{node1, node2}));
  Node* node4(new Node(2, vector<Node*>()));
  Node* node5(new Node(4, vector<Node*>()));
  Node* node6(new Node(1, vector<Node*>{node3, node4, node5}));

  vector<int> ans = {1, 3, 5, 6, 2, 4};
  EXPECT_EQ(ans, s_.preorder(node6));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}             

