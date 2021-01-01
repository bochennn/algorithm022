/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

*/
#include <gtest/gtest.h>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    //bool cmp(pair<int, int>& m, pair<int, int>& n) {
    //  return m.second > n.second;
    //}
    struct cmp {
      bool operator()(pair<int, int>& m, pair<int, int>& n) const {
        // 小的优先级高
        return m.second < n.second;
      }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
      // 1 统计每个值之后做一次频次排序 O(nlogn)
      // 2 heap 对于需要统计前K个最大/小值时适用, 在插入数值之前以做好排序
      unordered_map<int, int> occurrences;
      for (auto& n : nums) {
        occurrences[n]++; // 统计频次
      }

      // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
      // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
      priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> max_heap;
      //for (auto& [num, count] : occurrences) {
      for (auto& it : occurrences) {
        //std::cout << "? " << it.first << "," << it.second << std::endl;
        max_heap.push(it);
        //if (max_heap.size() > k) {
        //  max_heap.pop();
        //}
      }
      vector<int> ret;
      for (int i = 0; i < k; i++) { // 输出前K个
        ret.push_back(max_heap.top().first);
        max_heap.pop();
      }
      return ret;
    }
};

Solution s_; 
TEST(CodeTest1, TopKFrequent) {
  vector<int> nums = {1, 1, 1, 1, 2, 2, 3};
  vector<int> ans = {1, 2};
  EXPECT_EQ(ans, s_.topKFrequent(nums, 2));
}

TEST(CodeTest2, TopKFrequent) {
  vector<int> nums = {1};
  vector<int> ans = {1};
  EXPECT_EQ(ans, s_.topKFrequent(nums, 1));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}             

