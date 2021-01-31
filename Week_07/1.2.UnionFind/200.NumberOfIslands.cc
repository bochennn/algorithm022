/* 200. Number of Islands
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


Example 1:

Input: grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]
Output: 1
Example 2:

Input: grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1',"1"]
]
Output: 3

@lc app=leetcode.cn id=200 lang=cpp
*/
#include <gtest/gtest.h>
using namespace std;

class UnionFind {
 public:
  UnionFind(vector<vector<char>>& grid) {
    count_ = 0;
    for (int i = 0; i < grid.size(); i++) { // 初始化时做相应修改
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          parent_.push_back(i * grid[i].size() + j);
          count_++;
        } else {
          parent_.push_back(-1);
        }
        rank_.push_back(0);
      }
      
    }
  }

  int find(int x) {
    return parent_[x] = (parent_[x] == x ? x : find(parent_[x]));
  }

  void merge(int x, int y) {
    int parent_x = find(x), parent_y = find(y);
    if (parent_x != parent_y) {
      if (rank_[parent_x] > rank_[parent_y]) {
        swap(parent_x, parent_y);
      }
      parent_[parent_x] = parent_y;
      if (rank_[parent_x] == rank_[parent_y]) {
        rank_[parent_y]++;
      }
      count_--;
    }
  }

  int count() const {
    return count_;
  }

 private:
  int count_;
  vector<int> parent_, rank_;
};


class Solution {
public:
  // void dfs(vector<vector<char>>& grid, int r, int c) {
  //   int nr = grid.size();
  //   int nc = grid[0].size();

  //   grid[r][c] = '0'; // 重标记
  //   if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c); // 上
  //   if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c); // 下
  //   if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1); // 左
  //   if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1); // 右
  // }

  int numIslands(vector<vector<char>>& grid) {
    // int num_of_islands = 0;
    // 扫描整个二维网络, 当遇到1时开始dfs搜索, 顺便在搜索之后将访问过的1重标记
    // 时间O(M*N) 空间(M*N)
    // for (int i = 0; i < grid.size(); i++) {
    //   for (int j = 0; j < grid[i].size(); j++) {
    //     if (grid[i][j] == '1') {
    //       num_of_islands++;
    //       dfs(grid, i, j);
    //     }
    //   }
    // }
    // return num_of_islands;
    
    // 并查集做法:
    int rows = grid.size();
    if (rows < 1) {
      return 0;
    }
    UnionFind uf(grid);

    
    for (int row = 0; row < rows; row++) {
      int cols = grid[row].size();
      auto node = [&](int x, int y) {
        return x * cols + y;
      };

      for (int col = 0; col < cols; col++) {
        if (grid[row][col] != '1') {
          continue;
        }

        if (row - 1 > 0 && grid[row - 1][col] == '1') {
          uf.merge(node(row, col), node(row - 1, col));
        }
        if (row + 1 < rows && grid[row + 1][col] == '1') {
          uf.merge(node(row, col), node(row + 1, col));
        }
        if (col - 1 > 0 && grid[row][col - 1] == '1') {
          uf.merge(node(row, col), node(row, col - 1));
        }
        if (col + 1 < cols && grid[row][col + 1] == '1') {
          uf.merge(node(row, col), node(row, col + 1));
        }
      }
    }
    return uf.count();
  }
};
// @lc code=end


Solution s_; 
TEST(CodeTest1, NumIslands) {
  vector<vector<char>> grid = { {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'} };

  EXPECT_EQ(1, s_.numIslands(grid));
}

TEST(CodeTest2, NumIslands) {
  vector<vector<char>> grid = { {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'} };
  EXPECT_EQ(3, s_.numIslands(grid));
}

TEST(CodeTest3, NumIslands) {
  vector<vector<char>> grid = { {'1','1'} };
  EXPECT_EQ(1, s_.numIslands(grid));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

