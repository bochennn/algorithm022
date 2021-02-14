/*
买卖股票问题
*/

class Solution {
public:
  // I. 一次买进一次卖出
  // dp[i] = max(dp[i-1], prices[i] - min_price)
  // O(n)/O(1)
  int maxProfit_1(vector<int>& prices) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      min_price = min(prices[i], min_price);
      max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
  }
  // II. 多次买进卖出
  // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]) 在第i天卖出
  // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]) 在第i天买进
  // O(n)/O(1)
  int maxProfit_2(vector<int>& prices) {
    int dp_i_0 = 0, dp_i_1;
    int dp_i_1_0 = 0, dp_i_1_1 = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
      dp_i_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
      dp_i_1 = max(dp_i_1_1, dp_i_1_0 - prices[i]);
      dp_i_1_0 = dp_i_0;
      dp_i_1_1 = dp_i_1;
    }
    return dp_i_0;
  }
  // III. 可完成两笔交易
  // 0-share,buy-1: dp[i][0] = max(dp[i-1][0], 0 - prices[i])
  // 1-share,sel-1: dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])
  // 1-share,buy-2: dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i])
  // 2-share,sel-2: dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i])
  int maxProfit_3(vector<int>& prices) {
    int dp_i_0 = -prices[0];
    int dp_i_1 = 0;
    int dp_i_2 = -prices[0];
    int dp_i_3 = 0;

    for (int i = 0; i < prices.size(); i++) {
      dp_i_0 = max(dp_i_0, 0 - prices[i]);
      dp_i_1 = max(dp_i_1, dp_i_0 + prices[i]);
      dp_i_2 = max(dp_i_2, dp_i_1 - prices[i]);
      dp_i_3 = max(dp_i_3, dp_i_2 + prices[i]);
    }
    return dp_i_3;
  }
  // IV. 可完成K笔交易
  // 1-share: dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
  // 0-share: dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
  int maxProfit_4(int k, vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int n = prices.size();
    k = min(k, n / 2);
    vector<vector<int>> dp_0(n, vector<int>(k+1, 0)),
                        dp_1(n, vector<int>(k+1, -prices[0]));
    for (int i = 1;i < n; i++) {
      for (int j = 1; j <= k; j++) {
        dp_0[i][j] = max(dp_0[i-1][j], dp_1[i-1][j] + prices[i]);
        dp_1[i][j] = max(dp_1[i-1][j], dp_0[i-1][j-1] - prices[i]);
      }
    }
    return dp_0[n-1][k];
  }
  // 含冷冻期
  // 1-share: dp[i][0] = max(dp[i-1][0], dp[i-1][2] - price[i])
  // 0-share: dp[i][1] = dp[i-1][0] + prices[i]
  // infroze: dp[i][2] = max(dp[i-1][1], dp[i-1][2])
  int maxProfit_5(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
      dp[i][1] = dp[i - 1][0] + prices[i];
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};


