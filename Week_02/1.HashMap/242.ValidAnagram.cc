/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

EASY

Unicode是为了解决传统字符编码的局限性而产生的方案，它为每个语言中的字符规定了一个唯一的二进制编码
Unicode中可能存在一个字符对应多个字节的问题
也就是说区别于不同的字节表示一个字符(没有完全明白)

*/
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      // 1. sort string and check if they are equal O(nlogn)
      // 2. hashmap/vector(26) O(n)
      
      // build hasp map
      unordered_map<char, int> map_t;
      for (char ch : t) {
        map_t[ch]++;
      }
      // 在新字符串遍历
      for (char ch : s) {
        auto it = map_t.find(ch);
        if (it != map_t.end()) {
          if (map_t[ch] > 1) {
            map_t[ch]--;
          } else {
            // 频次抵消之后应该删除
            map_t.erase(it);
          }
        } else {
          return false;
        }
      }
      return map_t.empty();
    }
};

Solution s_;
TEST(CodeTest1, ValidAnagram) {
  EXPECT_EQ(true, s_.isAnagram("anagram", "nagaram"));
}

TEST(CodeTest2, ValidAnagram) {
  EXPECT_EQ(false, s_.isAnagram("rat", "car"));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

