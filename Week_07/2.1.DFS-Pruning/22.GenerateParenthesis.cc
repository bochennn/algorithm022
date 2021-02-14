/* [22][Medium] Generate Parentheses 括号生成

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


 */
#include <gtest/gtest.h>
using namespace std;

class Solution {
 public:
  void generate(vector<string>& res, string parenthesis, int lp, int rp, int n) {
    /*if (lp == n && rp == n) {
      res.push_back(parenthesis);
    }
    if (parenthesis.size() == n * 2) {
      return;
    }

    if (lp < n) {
      generate(res, parenthesis + "(", lp + 1, rp, n);
    }
    if (lp > 0 && lp > rp) { // 增加限制条件
      generate(res, parenthesis + ")", lp, rp + 1, n);
    }*/

    // dp:
    vector<vector<string>> dp(n + 1);
    dp[0] = vector<string>{""};
      
    for (int i = 1; i <= n; i++) {
      vector<string> cur;
        
      for (int m = 0; m < i; m++) {
        int k = i - 1 - m;
        vector<string> str1 = dp[m];
        vector<string> str2 = dp[k];
          
        for (string s1 : str1) {
          for (string s2 : str2) {
            cur.emplace_back("(" + s1 + ")" + s2);
          }
        }
      }
      dp[i] = cur;
    }
    return dp[n];
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    generate(res, "", 0, 0, n); // 从1开始generate
    return res;
  }
};

Solution s_;
TEST(CodeTest1, GenerateParenthesis) {
  vector<string> res = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  EXPECT_EQ(res, s_.generateParenthesis(3));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

