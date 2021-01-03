/* [77][Medium] Combinations 组合
  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

  You may return the answer in any order.

  Example 1:

  Input: n = 4, k = 2
  Output:
  [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
  ]
  Example 2:

  Input: n = 1, k = 1
  Output: [[1]]
 */
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  void backtracking(vector<vector<int>>& res, vector<int>& combination, int startIndex, int n, int k) {
    if (combination.size() == k) {
      res.push_back(combination);
      return;
    }
    // i到n的排列组合
    for (int i = startIndex; i <= n; i++) {
      combination.push_back(i); // 添加一项
      backtracking(res, combination, i + 1, n, k); // 递归
      combination.pop_back(); // 回溯, 撤销添加项
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> combination;
    backtracking(res, combination, 1, n, k);
    return res;
  }
};


Solution s_;
TEST(CodeTest1, Combinations) {
  vector<vector<int>> ans{vector<int>{1, 2}, vector<int>{1, 3}, vector<int>{1, 4}, 
                          vector<int>{2, 3}, vector<int>{2, 4}, vector<int>{3, 4}};

  EXPECT_EQ(ans, s_.combine(4, 2));
}

TEST(CodeTest2, Combinations) {
  vector<vector<int>> ans{vector<int>{1}};

  EXPECT_EQ(ans, s_.combine(1, 1));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}