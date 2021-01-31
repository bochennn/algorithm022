/*
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2


Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

*/
#include <gtest/gtest.h>
using namespace std;

class UnionFind {
 public:
  UnionFind(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
      parent_.push_back(i);
      rank_.push_back(0);
    }
    count_ = matrix.size();
  }

  int find(int x) {
    return parent_[x] = (parent_[x] == x ? x : find(parent_[x]));
  }

  void merge(int x, int y) {
    int root_x = find(x), root_y = find(y);
    if (root_x != root_y) {
      if (rank_[root_x] > rank_[root_y]) {
        swap(root_x, root_y);
      }
      parent_[root_x] = root_y;
      if (rank_[root_x] == rank_[root_y]) {
        rank_[root_y]++;
      }
      count_--;
    }
  }

  int count_;
  vector<int> parent_, rank_;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.count_;
    }
};

