/*

*/

class Solution {
public:
  string longestPalindrome(string s) {
    string res;
    int n = s.size();
    if (n < 1) {
      return res;
    }
    // dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]>0) ? dp[i+1][j-1] + 2 : 0
    // 定义子串的下标
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) { // 列
      for (int i = 0; i <= j; i++) { // 行
        // 字符相同
        if (s[i] == s[j]) {
          if (j - i < 2) { // j-i==0时dp为1, j-i==1时dp为2
            dp[i][j] = j - i + 1;
          } else if (dp[i + 1][j - 1]) { // 当内部为回文子串时再算
            dp[i][j] = dp[i + 1][j - 1] + 2;
          }
        }
        if (dp[i][j] > res.size()) {
          res = s.substr(i, dp[i][j]);
        }
      }
    }
    return res;
  }
};


