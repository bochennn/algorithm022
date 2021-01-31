/*
130. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
#include <gtest/gtest.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class UnionFind {
 public:
  UnionFind(int n) {
    count_ = n;
    parent_.resize(n);
    rank_.resize(n);

    for (int i = 0; i < n; i++) {
      parent_[i] = i; // 存顺序排序的下角标
      rank_[i] = 0;
    }
  }

  int find(int x) {
    // 递归形式
    // 未压缩!!! 如果不改当前下角标的话, 递归次数可能会很大
    // return parent_[x] == x ? parent_[x] : find(parent_[x]);
    // 路径压缩!!! 直接指向顶元素的下角标
    return parent_[x] = (parent_[x] == x ? x : find(parent_[x]));
  }

  void merge(int x, int y) {
    int rootx = find(x), rooty = find(y);
    if (rootx != rooty) { // 不属于同一个集合才合并
      if (rank_[rootx] > rank_[rooty]) {
        swap(rootx, rooty); // 目的是尽可能让新元素指向已经合并过的集合
      }
      parent_[rootx] = rooty; // 合并之后将原下角标指向代表集合顶元素的下角标
      if (rank_[rootx] == rank_[rooty]) { // 如果y就是顶元素
        rank_[rooty]++;
      }
      count_--; // 元素合并之后, 集合数-1
    }
  }

 private:
  int count_; // 表示集合的个数
  vector<int> parent_, rank_;
};


class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int board_rows = board.size();
    if (board_rows < 1) {
      return;
    }
    int board_cols = board[0].size();

    int dummy = board_rows * board_cols;
    UnionFind uf(dummy + 1);

    auto node = [&](int i, int j) {
      return i * board_cols + j;
    };

    for (int row = 0; row < board_rows; row++) {
      for (int col = 0; col < board_cols; col++) {
        if (board[row][col] != 'O') {
            continue;
        }

        // 将边缘的O与dummy并集
        if (row == 0 || (row == board_rows - 1) || col == 0 || (col == board_cols - 1)) {
          uf.merge(node(row, col), dummy);
        } else {
          if (row - 1 > -1 && board[row - 1][col] == 'O') {
            uf.merge(node(row, col), node(row - 1, col)); // 与左边并集
          }
          if (row + 1 < board_rows && board[row + 1][col] == 'O') {
            uf.merge(node(row, col), node(row + 1, col));
          }
          if (col - 1 > -1 && board[row][col - 1] == 'O') {
            uf.merge(node(row, col), node(row, col - 1));
          }
          if (col + 1 < board_cols && board[row][col + 1] == 'O') {
            uf.merge(node(row, col), node(row, col + 1));
          }
        }
      }
    }

    for (int row = 0; row < board_rows; row++) {
        for (int col = 0; col < board_cols; col++) {
            if (board[row][col] == 'O' && uf.find(node(row, col)) != uf.find(dummy)) {
                board[row][col] = 'X';
            }
        }
    }
  }
};
// @lc code=end




