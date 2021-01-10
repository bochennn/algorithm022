/* 33. Search in Rotated Sorted Array
You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) { // 每一次循环后目标减半 时间O(logn) 空间O(1)
      int mid = (lo + hi) / 2;
      // [0, mid]升序 && (target落在[mid, hi]区间)
      if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0])) {
        lo = mid + 1;
      // [0, mid]存在旋转位 && (target落在[mid, hi]区间)
      } else if (target > nums[mid] && target < nums[0]) {
        lo = mid + 1;
      } else {
        hi = mid; // 向前规约
      }
    }
    return lo == hi && nums[lo] == target ? lo : -1;
  }
};
