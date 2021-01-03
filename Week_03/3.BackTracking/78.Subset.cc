/* [78][Medium] Subsets 子集

Given an integer array nums, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 */
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
  void backtracking(vector<vector<int>>& res, vector<int>& subset,
                      int cur, int end) {
    if (cur == end) {
      res.emplace_back(subset);
      return;
    }

    backtracking(res, subset, cur + 1, end); // 先后顺序不同结果一致
    subset.push_back(nums_[cur]);
    backtracking(res, subset, cur + 1, end);
    subset.pop_back();
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    nums_ = nums;
    backtracking(res, subset, 0, nums.size());
    return res;
  }
  vector<int> nums_;
};


Solution s_;
TEST(CodeTest1, Permutations) {
  vector<int> input{1, 2, 3};
  vector<vector<int>> ans{vector<int>{}, vector<int>{3}, vector<int>{2}, 
                          vector<int>{2, 3}, vector<int>{1}, vector<int>{1, 3}, 
                          vector<int>{1, 2}, vector<int>{1, 2, 3}};

  EXPECT_EQ(ans, s_.subsets(input));
}

TEST(CodeTest2, Permutations) {
  vector<int> input{0};
  vector<vector<int>> ans{vector<int>{}, vector<int>{0}};

  EXPECT_EQ(ans, s_.subsets(input));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
