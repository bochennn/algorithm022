/*
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

双指针, 左指针指向当前已经处理好的序列的尾部, 右指针指向待处理序列的头部
右指针不断向右移动, 每次右指针指向非0数时, 与做指针元素交换, 同时左指针++
使用swap(nums[l], nums[r])实现元素交换

left          left++               left
 |             |                    |
 0 1 0 3 12 -> 0 1 0 3 12 -swap-> 1 0 0 3 12 ->
 |               |                    |
right++         right++              right++

 left++               left++                left
  |                    |                     |
1 0 0 3 12 -swap-> 1 3 0 0 12 -swap-> 1 3 12 0 0
      |                    |                     |
     right++              right++               right

这样每次左指针指向第一次遇到的0, 在其之前的元素已经完成
右指针指向待交换元素, 遇到非0时交换, 继续遇到0时扩大双指针间隔
双指针中间总是0

*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size(), left = 0, right = 0;
    while (right < n) {
      if (nums[right]) {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};

Solution s_;
TEST(CodeTest1, MoveZeroes) {
  vector<int> nums = {0, 0};
  vector<int> ans = {0, 0};
  
  s_.moveZeroes(nums);
  EXPECT_EQ(ans, nums);
}

TEST(CodeTest2, MoveZeroes) {
  vector<int> nums = {0, 1, 0, 3, 12};
  vector<int> ans = {1, 3, 12, 0, 0};
  
  s_.moveZeroes(nums);
  EXPECT_EQ(ans, nums);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

