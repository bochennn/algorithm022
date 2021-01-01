/*
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

N叉树前序遍历: 从根节点出发递归

*/
#include <gtest/gtest.h>
#include <queue>
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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    queue<Node*> que;
    if (root != nullptr)
      que.push(root);

    while (!que.empty()) {
      vector<int> vec;
      for (int i = 0, que_size = que.size(); i < que_size; i++) {
        Node* node = que.front();
        que.pop();
        vec.push_back(node->val);
        for (Node* child : node->children) {
          que.push(child);
        }
      }
      res.push_back(vec);
    }
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

  vector<vector<int>> ans = {{1}, {3, 2, 4}, {5, 6}};
  EXPECT_EQ(ans, s_.levelOrder(node6));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}             

