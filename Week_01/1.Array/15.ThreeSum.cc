/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    if (size < 3)
      return {};

    vector<vector<int> >res;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++) {      // 固定第一个数，转化为求两数之和
      if (nums[i] > 0)
        return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
          
      if (i > 0 && nums[i] == nums[i - 1]) // 跟上一值相同时跳过
        continue;
      // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
      int left = i + 1;
      int right = size - 1;
      while (left < right) {
        if (nums[left] + nums[right] > -nums[i]) {
          right--;    // 两数之和太大，右指针左移
        } else if (nums[left] + nums[right] < -nums[i]) {
          left++;     // 两数之和太小，左指针右移
        } else {
          // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
          res.push_back(vector<int>{nums[i], nums[left], nums[right]});
          left++;
          right--;
          // 去重：第二个数和第三个数也不重复选取
          // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
          while (left < right && nums[left] == nums[left-1]) {
            left++;
          }
          while (left < right && nums[right] == nums[right+1]) {
            right--;
          }
        }
      }
    }
    return res;
  }
};


Solution s_;
TEST(CodeTest1, ThreeSum) {
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans{{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(ans, s_.threeSum(nums));
}

TEST(CodeTest2, ThreeSum) {
  vector<int> nums = {0, 1, 0, 3, 12};
  vector<int> ans = {1, 3, 12, 0, 0};
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

