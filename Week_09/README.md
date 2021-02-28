# 学习笔记 #

#### 动态规划 ####
经典面试问题的dp方程:

+ **爬楼梯问题**: `dp[i] = dp[i-1] + dp[i-2]`, 时间为O(n), 空间上可优化为O(1). 另外在此基础上的问题拓展, 

+ **不同路径**: `dp[x][y] = dp[x-1][y] + dp[x][y-1]` **有障碍物时**`dp[i][j]=0`

+ **打家劫舍**: `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`, 二维定义: `dp[i][0] = max(dp[i-1][0], dp[i-1][1]); dp[i][1] = dp[i-1][0] + nums[i]`

+ **最小路径和**: `dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + A[i][j]`

+ **股票买卖**: `dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]); dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])` [参考](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/javayi-ge-si-lu-da-bao-suo-you-gu-piao-t-pd1p/)

+ **跳跃游戏**: 

+ **青蛙过河**: `dp[i][k] = dp[j][k-1] || dp[j][k] || dp[j][k+1]`

+ **回文子串**: `dp[i][j] = (s[i] == s[j] && s[i+1][j-1]) ? s[i+1][j-1] + 2 : 0`

+ **最长子序列**: `dp[i][j] = (s1[i-1]==s2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1])` 子串时为`0`

+ **成对括号**: `dp[i+1][j-1] `

