/*
18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.


Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []

*/
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;
    if (n < 4) {
      return res;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      } 

      for (int j = i + 1; j < n - 2; j++) {
        // 重复
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        int left = j + 1, right = n - 1; // 双指针
        while (left < right) {
          int nsum = nums[i] + nums[j] + nums[left] + nums[right];
          if (nsum == target) {
            res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }

            left++;
            right--;
          } else if (nsum < target) { // 说明需要向右找个更大的值
            left++;
          } else {
            right--;
          }
        }
      }
    }
    return res;
  }
};


Solution s_;
TEST(CodeTest1, FourSum) {
  vector<int> nums{-2, -1, -1, 1, 1, 2, 2};
  vector<vector<int>> ans{{-2, -1, 1, 2}, {-1, -1, 1, 1}};
  EXPECT_EQ(ans, s_.fourSum(nums, 0));
}

TEST(CodeTest2, FourSum) {
  vector<int> nums{1, 0, -1, 0, -2, 2};
  vector<vector<int>> ans{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  EXPECT_EQ(ans, s_.fourSum(nums, 0));
}

TEST(CodeTest3, FourSum) {
  vector<int> nums{-3,-1,0,2,4,5};
  vector<vector<int>> ans{{-3, -1, 0, 4}};
  EXPECT_EQ(ans, s_.fourSum(nums, 0));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

