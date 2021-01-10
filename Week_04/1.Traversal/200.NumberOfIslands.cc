/* 200. Number of Islands
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

class Solution {
public:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0'; // 重标记
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c); // 上
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c); // 下
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1); // 左
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1); // 右
  }

  int numIslands(vector<vector<char>>& grid) {
    int num_of_islands = 0;
    // 扫描整个二维网络, 当遇到1时开始dfs搜索, 顺便在搜索之后将访问过的1重标记
    // 时间O(M*N) 空间(M*N)
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          num_of_islands++;
          dfs(grid, i, j);
        }
      }
    }
    return num_of_islands;
  }
};
