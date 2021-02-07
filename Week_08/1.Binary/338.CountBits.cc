/*
191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above, the input represents the signed integer. -3.
Follow up: If this function is called many times, how would you optimize it?

 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

Constraints:

The input must be a binary string of length 32
*/
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    // 法1 按最高位为一个循环周期, 这个周期内的计数比去除最高位的计数多1
    // i.e. 1, 10, 100, 1000
    // dp: f(i + b) = f(i) + 1, 0 < i < b, b is 2^n
    vector<int> res(num + 1);
    int i = 0, b = 1;
    // // [0, b)
    res[0] = 0;
    // while (b <= num) {
    //     // 统计[b, 2b)范围
    //     while (i < b && i + b <= num) {
    //         // [b,2b)范围内的比[0,b)的计数多1
    //         // [2b,4b)比[0,2b)多1, 以此类推
    //         res[b + i] = res[i] + 1;
    //         ++i;
    //     }
    //     i = 0;
    //     b <<= 1;
    // }
    // return res;

    // 法2 按最低位来判断, f(i) = f(i>>1) + (i & 1)
    // while (i <= num) {
    //     res[i] = res[i>>1] + (i & 1);
    //     ++i;
    // }

    // 法3 按最右第一个1判断, f(i) = f(i & (i - 1)) + 1 最右第一个1变为0
    i = 1;
    while (i <= num) {
      res[i] = res[i & (i - 1)] + 1;
      ++i;
    }
    return res;
  }
};
