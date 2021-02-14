/*
680. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/


class Solution {
public:
  bool isPalindrome(string s, int lo, int hi) {
    while (lo < hi) {
      if (s[lo] != s[hi]) {
        return false;
      }
      lo++;
      hi--;
    }
    return true;
  }

  bool validPalindrome(string s) {
    if (s.size() < 3) {
      return true;
    }
    // 双指针从两个方向遍历, 遇到一次字符不同时使用substring检查子串是否是回文
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
      if (s[lo] != s[hi]) {
        // 在构造函数的时候注意,如果要使用substr传下去的时候边界得写对
        return isPalindrome(s, lo + 1, hi) || 
               isPalindrome(s, lo, hi - 1);
      }
      lo++;
      hi--;
    }
    return true;
  }
};

