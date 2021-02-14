/*
37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
 

Example 1:

Input: board = [{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}]
Output: [{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}]
Explanation: The input board is shown above and the only valid solution is shown below:


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  bool is_filled(int r, int c, int digit) {
    // 如果该对应的二进制位为1的话, 余数应该大于等于左移的值
    return row[r] % (1 << digit + 1) >= (1 << digit) || 
           col[c] % (1 << digit + 1) >= (1 << digit) || 
           block[r / 3][c / 3] % (1 << digit + 1) >= (1 << digit);
  }

  void flip(int r, int c, int digit) {
    // 以000000000表示的填空状态
    row[r] ^= (1 << digit);
    col[c] ^= (1 << digit);
    block[r / 3][c / 3] ^= (1 << digit);
  }

  void dfs(vector<vector<char>>& board, int pos) {
    if (pos == spaces.size()) {
        valid = true;
    }

    int r = spaces[pos].first;
    int c = spaces[pos].second;

    for (int digit = 0; digit < 9 && !valid; ++digit) {
      // 下探
      // 此时应该是把当前所有可能填的数字都放进去下探, 如果任意一次发现0-9都填不进去的话就向上回溯
      // if (!row[r][digit] && !column[c][digit] && !block[r / 3][c / 3][digit]) {
      //     row[r][digit] = column[c][digit] = block[r / 3][c / 3][digit] = true; 
      //     board[r][c] = digit + '0' + 1;
      //     dfs(board, pos + 1);
      //     // 回溯
      //     row[r][digit] = column[c][digit] = block[r / 3][c / 3][digit] = false; 
      // }
      if (!is_filled(r, c, digit)) {
        flip(r, c, digit);
        board[r][c] = digit + '0' + 1;
        dfs(board, pos + 1);
        flip(r, c, digit);
      }
    }
  }

  void solveSudoku(vector<vector<char>>& board) {
    // 存储每行每列是否填完
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));
    valid = false;

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.') {
          spaces.emplace_back(r, c); // 记录需要填的空格
        }
        else {
          int digit = board[r][c] - '0' - 1; // [0-8]
          // 该行/列都有哪些数字已经填过
          // row[r][digit] = column[c][digit] = 
          // block[r / 3][c / 3][digit] = true;
          flip(r, c, digit);
        }
      }
    }
    dfs(board, 0); // 按每个空格遍历
  }

private:
  // bool row[9][9], column[9][9], block[3][3][9];
  int row[9], col[9], block[3][3]; // 状态压缩
  vector<pair<int, int>> spaces; // 空格位置
  bool valid = false;
};



Solution s_;
TEST(CodeTest1, SolveSudoku) {
  vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  vector<vector<char>> res{{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};
  
  s_.solveSudoku(board);
  EXPECT_EQ(res, board);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

