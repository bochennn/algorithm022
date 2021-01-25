/*
221. Maximal Square
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
*/

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    // brutal force: 遍历时遇到1则开始扩展,扩展时第一行确认最大行数
    // 向下扩展最大列数, 中间遇到0时缩减其范围
    // dp[i][j]表示矩形i*j的最大正方形
    // 状态转移方程为: dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
    int rows = matrix.size(), cols = matrix[0].size();
    int res = 0; // 表示最大边长
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == '1') {
          // 计算边缘时直接用source
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
          }
        }
        res = max(res, dp[i][j]);
      }
    }
    return res*res;
  }
};

