/*
541. Reverse String II
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/


class Solution {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int start = 0; start < n; start += 2 * k) { // 每2k个字符为一段
      int lo = start;
      int hi = std::min(start + k - 1, n - 1); // 需考虑剩余字符不足k的情况
      while (lo < hi) {   // 反转[i,j]区间内的字符
        std::swap(s[lo++], s[hi--]);
      }
    }
    return s;
  }
};


