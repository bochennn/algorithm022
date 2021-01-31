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

*/

class Solution {
public:
  int longestValidParentheses(string s) {
    // dp[i][j] = true if 
    // 1. dp[i+1][j-1] && dp[i] == '(' && dp[j] == ')'
    // 2. dp[i][j-2] && dp[j-1] == '(' && dp[j] == ')' 
    // 

    int n = s.size();
    vector<int> dp(n, 0);
    int max_val = 0;

    for (int i = 1; i < n; i++) {
      if (s[i] == ')') { // 遇到右括号时才处理
        if (s[i - 1] == '(') {
          dp[i] = 2; // 遇到一对
          if (i - 2 >= 0) {
            dp[i] = dp[i] + dp[i - 2]; // 加上之前已有的
          }
        } else if (dp[i - 1] > 0) {
          // dp[i - 1]必须有效对, 那么s[i - 1]是')'
          // 并且dp[i - 1]的前一项是'('
          if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i - 1] - 2 >= 0) {
              dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
            }
          }
        }
      }
      max_val = max(dp[i], max_val);
    }
    return max_val;
  }
};




