/*
44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = p.size(), n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = true;
    // 先遍历p中以*开头的字符
    for (int i = 1; i <= m; i++) {
      if (p[i-1] == '*') {
        dp[0][i] = true;
      } else {
        break;
      }
    }
    // dp[0][0] = 1
    // dp[i][j] = dp[i-1][j-1] if s[i]==p[j] | p[j]=='?'
    // dp[i][j] = dp[i-1][j] | dp[i][j-1] if p[j]=='*'
    // else dp[i][j] = 0
    for (int i = 1; i <= n; i++) { // s
      for (int j = 1; j <= m; j++) { // p
        if (p[j-1] == '*') {
          dp[i][j] = dp[i][j-1] | dp[i-1][j];
        } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
          dp[i][j] = dp[i-1][j-1];
        }
      }
    }
    return dp[n][m];
  }
};



