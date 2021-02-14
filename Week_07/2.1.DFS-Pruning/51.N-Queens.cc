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

class Solution {
public:
  void backtrack(vector<vector<string>>& res, vector<string>& distribute, 
                int row, int n,
                unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
    // terminator
    if (row == n) {
      res.push_back(distribute);
      return;
    }

    // 因为每行肯定只能放一个, 所以适合按行递归
    // 在递归中每次在第n列上assign一个, 则在相应set中记录其所属列
    for (int c = 0; c < n; c++) {
      if (columns.count(c)) {
        continue;
      }
      // trick1: 右对角线可用row - col区分
      int diagonal1 = row - c;
      if (diagonals1.count(diagonal1)) {
        continue;
      }
      // trick2: 左对角线可用row + col区分
      int diagonal2 = row + c;
      if (diagonals2.count(diagonal2)) {
        continue;
      }

      columns.insert(c);
      diagonals1.insert(diagonal1);
      diagonals2.insert(diagonal2);
      distribute[row][c] = 'Q';
      backtrack(res, distribute, row + 1, n, columns, diagonals1, diagonals2);

      distribute[row][c] = '.';
      columns.erase(c);
      diagonals1.erase(diagonal1);
      diagonals2.erase(diagonal2);
    }
  }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<string> distribute(n, string(n, '.')); // 二维distribute转一维 1:queen, 0:unsafe, -1:unassign
      unordered_set<int> columns, diagonals1, diagonals2;

      backtrack(res, distribute, 0, n, columns, diagonals1, diagonals2);
      return res;
    }
};





