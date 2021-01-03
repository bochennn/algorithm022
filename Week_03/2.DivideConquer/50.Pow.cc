/* [50][Medium] Pow(x, n)
  Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

  Example 1:
  Input: x = 2.00000, n = 10
  Output: 1024.00000

  Example 2:
  Input: x = 2.10000, n = 3
  Output: 9.26100
  
  Example 3:
  Input: x = 2.00000, n = -2
  Output: 0.25000
  Explanation: 2-2 = 1/22 = 1/4 = 0.25
 */
#include <gtest/gtest.h>
// 分治
class Solution {
 public:
  double fastPow(double x, long long n) {
    if (n == 0) {
      return 1.;
    }

    double half = fastPow(x, n / 2);
    if (n % 2 ==0) {
      return half * half;
    } else {
      return half * half * x;
    }
  }
  double myPow(double x, int n) {
    long long N = n;
    if (n < 0) {
      x = 1 / x;
      N = -N;
    }
    return fastPow(x, N);
  }
};


Solution s_;
TEST(CodeTest1, Pow) {
  EXPECT_DOUBLE_EQ(1024.00000, s_.myPow(2.00000, 10));
}
TEST(CodeTest2, Pow) {
  EXPECT_DOUBLE_EQ(9.26100, s_.myPow(2.10000, 3));
}
TEST(CodeTest3, Pow) {
  EXPECT_DOUBLE_EQ(0.25000, s_.myPow(2.00000, -2));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
