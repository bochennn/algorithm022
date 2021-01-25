/*
120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

*/
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    // dp
    // 1. 确定状态: 用dp[i][j]表示从0,0走到i,j的最小路径，每一步只能走到下一行
    // 2. 转移方程: dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])
    // 3. 计算顺序: 子下向上更合适，反方向不方便包含所有的节点
    // 4. 初始条件和边界情况: n-1不动，从n-2层开始逐级存储从当前点到最末端的最小路径和

    vector<vector<int>> dp = triangle;
    for (int i = dp.size() - 2; i >= 0; i--) { // 从n-2层开始
      for (int j = 0; j < dp[i].size(); j++) {
        dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
      }
    }
    return dp[0][0];
  }

  int minimumTotal1(vector<vector<int>>& triangle) {
    vector<int> res = triangle[triangle.size() - 1];
    // 将dp转为一维 因为当自下而上时，数组长度总是比上一层小
    // 这样可以将空间复杂度从O(mn)减至O(m)
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        // 因为至牵扯到下一层的[j]和[j+1]
        // 所以带着res处理上一层时，每一次j++可直接覆盖res[j]，并作为当前节点的结果
        res[j] = min(res[j], res[j+1]) + triangle[i][j];
      }
    }
    return res[0];
  }
};

Solution s_; 
TEST(CodeTest1, MinimumTotal) {
  vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
  EXPECT_EQ(11, s_.minimumTotal1(triangle));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

