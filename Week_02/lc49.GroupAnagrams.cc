/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


*/
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // 自制hashmap
  int hash(string s) {
    if (!s.size()) return 0;
    int ans = 0;
    for (char i: s) {
      ans = ans + 5*i*i*i/26 + i*1009 - i*i*997; // 尽量让哈希散列的范围较大就行了。避免不必要的碰撞。
    }
    return ans;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // 以排序后的str映射每个字符串成员
    // unordered_map<string, vector<string>> mp;
    // for (string str : strs) {
    //     // 按字母排序
    //     string key = str;
    //     sort(key.begin(), key.end()); // 时间复杂度k * logk
    //     // 遇到新字符串时新建
    //     mp[key].emplace_back(str);
    // }

    // vector<vector<string>> out_strs;
    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     out_strs.emplace_back(it->second);
    // }
    // return out_strs;
    if (!strs.size())
      return {};

    vector<vector<string>> ans;
    int index = 0;
    unordered_map<int, int> map; // hash_id, vector_idx
        
    for (int i = 0; i < strs.size(); i ++ ) {
      int t = hash(strs[i]);
      if (map.find(t) != map.end()) {
        ans[map[t]].push_back(strs[i]);
      } else {
        map[t] = index; // 对应ans的下标
        index++;
        vector<string> temp;
        temp.push_back(strs[i]);
        ans.push_back(temp);
      }
    }
    return ans;
  }
};


Solution s_; 
TEST(CodeTest1, GroupAnagrams) {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans =  {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
  EXPECT_EQ(ans, s_.groupAnagrams(strs));
}

TEST(CodeTest2, GroupAnagrams) {
  vector<string> strs = {""};
  vector<vector<string>> ans = {{""}};
  EXPECT_EQ(ans, s_.groupAnagrams(strs));
}

TEST(CodeTest3, GroupAnagrams) {
  vector<string> strs = {"a"};
  vector<vector<string>> ans = {{"a"}};
  EXPECT_EQ(ans, s_.groupAnagrams(strs));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}   


