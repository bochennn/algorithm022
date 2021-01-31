/*
70. Climbing Stairs
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


class Solution {
public:
  int climbStairs1(int n) {
    // dp: f(x) = f(x - 2) + f(x - 1)
    int step_n_2 = 1;
    int step_n_1 = 1;
    if (n < 2) {
      return 1;
    }

    int step_n;
    for (int i = 1; i < n; i++) {
      step_n = step_n_2 + step_n_1;
      step_n_2 = step_n_1;
      step_n_1 = step_n;
    }
    return step_n;
  }

  int climbStairs2() {
		// 矩阵快速幂
    // |1  1| | f(n) |   |f(n) + f(n-1)|   |f(n+1)|
    // |1  0| |f(n-1)| = |    f(n)     | = | f(n) |
    //
    // |f(n+1)|   |1  1|^n |f(1)|
    // | f(n) | = |1  0|   |f(0)|
    return 0;
  }
};













