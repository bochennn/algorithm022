/*
51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/
#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

// 二进制写法 终极解法

class Solution {
public:
  void backtrack(vector<vector<string>>& res, vector<string>& distribute, 
                  int row, int n,
                  int columns, int diagonals1, int diagonals2) {
    // terminator
    if (row == n) {
      res.push_back(distribute);
      return;
    }
    // 最终解法, 用9位二进制存储状态
    // column比较直观, 而diag1, diag2表示next row的占位
    // 那么每次下探到next row, col不变, diag1右移, diag2左移
    int avalible = ~(columns | diagonals1 | diagonals2) & ((1 << n) - 1);
    while (avalible) {
      int c_binary = -avalible & avalible;
      avalible = avalible & (avalible - 1); // 将最低位1置0
      int col = __builtin_ctz(c_binary);
      distribute[row][col] = 'Q';
      backtrack(res, distribute, row + 1, n, 
                  columns | c_binary, 
                  (diagonals1 | c_binary) >> 1, 
                  (diagonals2 | c_binary) << 1); // 当前层状态没有改写所以省了回溯
      distribute[row][col] = '.';
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> distribute(n, string(n, '.'));

    backtrack(res, distribute, 0, n, 0, 0, 0);
    return res;
  }
};



