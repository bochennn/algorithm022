/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

class Solution {
public:
  int longestValidParentheses(string s) {
    // dp[i][j] = dp[i+1][j-1] + 2 if s[i] == ')' && s[i-1] == '('
    // dp[i][j] = dp[]
    int res = 0;
    int n = s.size();
    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++) {
      if (s[i] == ')') {
        if (s[i-1] == '(') {
          dp[i] = 2 + (i - 2 >= 0 ? dp[i] + dp[i-2] : 0);
        } else if (dp[i-1] > 0) {
          if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
            dp[i] = dp[i-1] + 2 + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0);
          } 
        }
      }
      res = max(dp[i], res);
    }
    return res;
  }
};

