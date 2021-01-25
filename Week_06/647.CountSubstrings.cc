/*
647. Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    // dp[i][j]表示从i到j是否为一个回文字符串 或者表示回文子串的长度
    // 动态方程: dp[i][j] = s[i] == s[j]? 0 : s[i+1][j-1] + 2
    // 用二维状态演示比较直观:
    //    j-->
    // i   a b c b a
    // | a 1
    // v b 0 1
    //   c 0 0 1
    //   b 0 3 0 1
    //   a 5 0 0 0 1

    int res = 0, n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));

    for (int j = 0; j < n; j++) { // 列
      for (int i = 0; i <= j; i++) { // 行 计算下三角
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1] > 0)) {
          dp[i][j] = true;
          res++;
        }
      }
    }
    return res;
  }
  // 顺便放上第五题
  string longestPalindrome(string s) {
    if (s.size() < 1) {
      return "";
    }

    string res(1, s[0]);
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) { // 列
      for (int i = 0; i <= j; i++) { // 行 计算下三角
        if (s[i] == s[j]) {
          if (j - i < 2) {
            dp[i][j] = j - i + 1;
          } else if (dp[i + 1][j - 1] > 0) {
            dp[i][j] = dp[i + 1][j - 1] + 2;
          }
          if (dp[i][j] > res.size()) {
            res = s.substr(i, dp[i][j]);
          }
        }
      }
    }
    return res;
  }
};

TEST(CodeTest1, longestPalindrome)
{
  Solution s_;
  EXPECT_EQ("bab", s_.longestPalindrome("babad"));
}

TEST(CodeTest2, longestPalindrome)
{
  Solution s_;                                                                                          
  EXPECT_EQ("bb", s_.longestPalindrome("cbbd"));
}

TEST(CodeTest3, longestPalindrome)
{
  Solution s_;
  EXPECT_EQ("a", s_.longestPalindrome("a"));
}

TEST(CodeTest4, longestPalindrome)
{
  Solution s_;
  EXPECT_EQ("a", s_.longestPalindrome("ac"));
}

TEST(CodeTest5, longestPalindrome)
{
  Solution s_;
  EXPECT_EQ("xaabacxcabaax", s_.longestPalindrome("xaabacxcabaaxcabaax"));
}

TEST(CodeTest6, longestPalindrome)
{
  Solution s_;
  EXPECT_EQ("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa", s_.longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}   

