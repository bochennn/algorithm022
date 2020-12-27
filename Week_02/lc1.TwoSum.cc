/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

EASY
*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
	  /* @Solution1: Brute Forse O(n) <= complex <= O(n^2)
     * time: 756ms, storage: 7.1MB
     */
    // vector<int> res(2);
		// for (int i = 0; i < nums.size(); i++) {
    //   for (int j = i + 1; j < nums.size(); j++) {
    //     if (nums[j] == target - nums[i]) {
    //       res.push_back(i);
    //       res.push_back(j);
    //       return res;
    //     }
    //   }
    // }
    // return res;

    /* @Solution2: Hash map O(1) <= complex <= O(n)
     * time: 16ms, storage: 8.2MB
     */
    vector<int> res;
    map<int, int> map_; // find the first argument
    for (int i = 0; i < nums.size(); i++) {
      auto it = map_.find(target - nums[i]); // map<int, int>::iterator
      if (it != map_.end()) { // 元素指针
        res.push_back(i);
        res.push_back(it->second);
        return res;
      }
      //map_.insert(pair<int, int>(nums[i], i)); // 插入哈希表<value, key>
      map_[nums[i]] = i;
    }
    return res;
  }
};

Solution s_;
TEST(CodeTest1, TwoSum) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  vector<int> result = {1, 0};
  EXPECT_EQ(result, s_.twoSum(nums, target));
}

TEST(CodeTest2, TwoSum) {
  vector<int> nums = {-1, -2, -3, -4, -5};
  int target = -8;
  
  vector<int> result = {4, 2};
  EXPECT_EQ(result, s_.twoSum(nums, target));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
