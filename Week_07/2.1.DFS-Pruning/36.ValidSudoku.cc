/*
36. 有效的数独
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
示例 2:

输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。

*/

#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  bool isvalid(vector<vector<char>>& board, int row, int col) {
    for (int k = 0; k < 9; k++) {
      // 对该格子所属行
      if (board[row][k] == board[row][col]) {
        if (k != col) {
          return false;
        }
      }
      // 该格子所属列
      if (board[k][col] == board[row][col]) {
        if (k != row) {
          return false;
        }
      }
      if (int grid_r = int(row / 3) * 3 + int(k / 3), 
              grid_c = int(col / 3) * 3 + k % 3;
          board[grid_r][grid_c] == board[row][col]) {
        if (grid_r != row && grid_c != col)
          return false;
      }
    }
    return true;
  }

  bool backtrace(vector<vector<char>>& board, int row, int col) {
    if (col == 9) {
      return backtrace(board, row + 1, 0); // 横着一行一行扫
    }
    if (row == 9) {
      return true;
    }

    if (board[row][col] == '.') {
      return backtrace(board, row, col + 1);
    }
    if (board[row][col]!='.') {
      if (!isvalid(board,row,col))
        return false;
      return backtrace(board, row, col + 1); // 遍历到每个格子
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    // 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
    // int row[9][10] = {0};
    // // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
    // int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
    // int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。

    // for (int r = 0; r < board.size(); r++) {
    //   for (int c = 0; c < board[r].size(); c++) {

    //     if (board[r][c] == '.')
    //       continue;

    //     int curr = board[r][c] - '0';
    //     if (row[r][curr]) return false;
    //     if (col[c][curr]) return false;
    //     if (box[(r / 3) * 3 + c / 3][curr]) return false;

    //     row[r][curr] = 1;
    //     col[c][curr] = 1;
    //     box[(r / 3) * 3 + c / 3][curr] = 1;
    //   }
    // }
    // return true;

    // dfs:
    return backtrace(board, 0, 0);
  }

};










