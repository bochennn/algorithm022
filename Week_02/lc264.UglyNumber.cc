/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

1.heap:
---
heap [1]
---
pop [1] push [2, 3, 5]
heap [2, 3, 5]
---
pop [1, 2] push [4, 6, 10]
heap [3, 5, 4, 6, 10]
---
pop [1, 2, 3] push [6, 9, 15]
heap [3, 5, 4, 6, 10, 9, 15]
---
pop [1, 2, 3, 4] push [8, 12, 20]
heap [4, 5, 6, 10, 9, 15, 8, 12, 20]
会有重复的数出现在heap中


2. dp:
没懂
g(n) = min(g(p_2)*2, g(p_3)*3, g(p_5)*5)

*/
#include <gtest/gtest.h>
#include <queue>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    priority_queue<size_t, vector<size_t>, greater<size_t>> que;
    size_t ans = 1;

    for (size_t i = 1; i < n; i++) {
      que.push(ans*2);
      que.push(ans*3);
      que.push(ans*5);
      ans = que.top();
      // 需要处理重复
      while(!que.empty() && que.top() == ans) {
        que.pop();
      }
    }
    return ans;
  }
};

Solution s_; 
TEST(CodeTest1, UglyNumber) {
  EXPECT_EQ(12, s_.nthUglyNumber(10));
}

TEST(CodeTest2, UglyNumber) {
  EXPECT_EQ(2123366400, s_.nthUglyNumber(1690));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}          

