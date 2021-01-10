/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
class Solution {
public:
  void bfs(vector<vector<int>>& res, TreeNode* root, int level) {
    if(!root) {
      return;
    }
    if (level >= res.size()) { // 抄到蛮好的层序遍历模版
      res.emplace_back();
    }
    res[level].push_back(root->val); // 对以遍历到的层继续做扩展

    bfs(res, root->left, level + 1);
    bfs(res, root->right, level + 1);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    bfs(res, root, 0);
    return res;
  }
};
