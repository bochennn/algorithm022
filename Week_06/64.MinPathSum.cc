/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

 
示例 1：


输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1->3->1->1->1 的总和最小。
示例 2：

输入：grid = [[1,2,3],[4,5,6]]
输出：12

*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    // dp
    // 对于网格求路径类型的题，优先考虑从起点向左第一行和向下第一列的情况
    // 因为这两个path只有单一的方向
    // 在这之后就比较容易向下处理子问题

    // 每个格子由相邻两个格子的较小权重值叠加
    // 先从边缘开始, 权重唯一
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }

    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols));
    dp[0][0] = grid[0][0];

    // 单独计算第一列 单方向
    for (int row = 1; row < rows; row++) {
      dp[row][0] = dp[row - 1][0] + grid[row][0];
    }
    // 单独计算第二列
    for (int col = 1; col < cols; col++) {
      dp[0][col] = dp[0][col - 1] + grid[0][col];
    }
    // 对于剩下的格子, 比较其上边和左边权值较小, 即为到该点的最小移动方式
    for (int row = 1; row < rows; row++) {
      for (int col = 1; col < cols; col++) {
        dp[row][col] = min(dp[row-1][col], dp[row][col-1]) + grid[row][col];
      }
    }

    return dp[rows - 1][cols - 1];
  }
};

Solution s_; 
TEST(CodeTest1, MinPathSum) {
  vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
  EXPECT_EQ(7, s_.minPathSum(grid));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}


