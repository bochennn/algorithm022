/* [70][Easy] Climbing Stairs 爬楼梯

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 */
#include <gtest/gtest.h>

class Solution {
public:
  int climbStairs(int n) {
    // 动态规划 f(x)=f(x−1)+f(x−2)
    // 爬到第 x 级台阶的方案数是爬到第 x−1 级台阶的方案数 和 
    // 爬到第 x−2 级台阶的方案数的和

    // 爬到n的方法数
    int steps_n;
    // 爬到n-2的方法数(n=2)
    int steps_n_2 = 0;
    // 爬到n-1的方法数(n=2)
    int steps_n_1 = 1;

    for (int i = 2; i < n+1; i++)
    {
      steps_n = steps_n_1 + steps_n_2;
      steps_n_2 = steps_n_1;
      steps_n_1 = steps_n;
    }

    return steps_n;
  }
};

Solution s_;
TEST(CodeTest1, ClimbStairs) {
  EXPECT_EQ(2, s_.climbStairs(2));
}

TEST(CodeTest2, ClimbStairs) {
  EXPECT_EQ(3, s_.climbStairs(3));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
