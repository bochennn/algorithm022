/* [46][Medium] Permutations 全排列
  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

  Example 1:

  Input: nums = [1,2,3]
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  Example 2:

  Input: nums = [0,1]
  Output: [[0,1],[1,0]]
  Example 3:

  Input: nums = [1]
  Output: [[1]]
 */
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
    // 递归到底
    if (first == len) {
      res.emplace_back(output);
      return;
    }
    // 从角标位置开始递归
    for (int i = first; i < len; ++i) {
      // backtrack(123,0)
      //   swap[0,0]->123
      //   backtrack(123,1)
      //     swap[1,1]->123
      //     backtrack(123,2)
      //       swap[2,2]->123
      //       backtrack(3)->push(123)
      //       swap_back[2,2]->123
      //     swap_back[1,1]->123
      //     swap[2,1]->132
      //     backtrack(132,2)
      //       swap[2,2]->132
      //       backtrack(3)->push(132)
      //       swap_back[2,2]->132
      //     swap_back[2,1]->123
      //   swap_back[0,0]->123
      // ...
      //     
      swap(output[i], output[first]); // i和first交换
      backtrack(res, output, first + 1, len);
      swap(output[i], output[first]); // 交换回来
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrack(res, nums, 0, nums.size());
    return res;
  }
};


Solution s_;
TEST(CodeTest1, Permutations) {
  vector<int> input{1, 2, 3};
  vector<vector<int>> ans{vector<int>{1, 2, 3}, vector<int>{1, 3, 2}, vector<int>{2, 1, 3}, 
                          vector<int>{2, 3, 1}, vector<int>{3, 2, 1}, vector<int>{3, 1, 2}};

  EXPECT_EQ(ans, s_.permute(input));
}

TEST(CodeTest2, Permutations) {
  vector<int> input{0, 1};
  vector<vector<int>> ans{vector<int>{0, 1}, vector<int>{1, 0}};

  EXPECT_EQ(ans, s_.permute(input));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

