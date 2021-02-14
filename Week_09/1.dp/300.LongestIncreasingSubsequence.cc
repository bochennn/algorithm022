/*
300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_len = 0;
    vector<int> dp(nums.size(), 0);
    // 双指针, 一个指向起始下标, 一个指向终点, 每次出现递增时dp计数加1
    // dp[i] = max(dp[j]) + 1 if nums[i] > nums[j]
    for (int i = 0; i < nums.size(); i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) { // 说明下标j到i满足递增关系
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_len = max(max_len, dp[i]);
    }
    return max_len;
    //return *max_element(dp.begin(), dp.end());
  }
};



