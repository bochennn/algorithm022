/* [47][Medium] Permutations Unique 全排列II
  Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


  Example 1:

  Input: nums = [1,1,2]
  Output:
  [[1,1,2],
  [1,2,1],
  [2,1,1]]
  Example 2:

  Input: nums = [1,2,3]
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

class Solution {
  public:
  int toInt(vector<int> combination) {
    int ans = 0;
    for (int i = 0; i < combination.size(); i++) {
      ans = ans * 10 + combination[i];
    }
    return ans;
  }
  void backtracking(vector<vector<int>>& res, vector<int>& combination,
    int startIndex, int n) {
    if (startIndex == n) {
      res.emplace_back(combination);
    }

    for (int i = startIndex; i < n; i++) {
      swap(combination[i], combination[startIndex]);
      nums_indx_[toInt(combination)]++;
      if (i == startIndex || nums_indx_[toInt(combination)] < 2) {
        backtracking(res, combination, startIndex + 1, n);
      }
      swap(combination[i], combination[startIndex]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> res;
    vector<int> combination;
    backtracking(res, nums, 0, n);

    return res;
  }
  unordered_map<int, int> nums_indx_;
};


Solution s_;
TEST(CodeTest1, PermutationsUnique) {
  vector<int> input{1, 2, 3};
  vector<vector<int>> ans{vector<int>{1, 2, 3}, vector<int>{1, 3, 2}, vector<int>{2, 1, 3}, 
                          vector<int>{2, 3, 1}, vector<int>{3, 2, 1}, vector<int>{3, 1, 2}};

  EXPECT_EQ(ans, s_.permuteUnique(input));
}

TEST(CodeTest2, PermutationsUnique) {
  vector<int> input{1, 1, 2};
  vector<vector<int>> ans{vector<int>{1, 1, 2}, vector<int>{1, 2, 1}, vector<int>{2, 1, 1}};

  EXPECT_EQ(ans, s_.permuteUnique(input));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
