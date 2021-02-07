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
  int hammingWeight(uint32_t n) {
    // ***对了解二进制机制比较重要的题
    // 法1 每次右移一位判断末尾是否为1
    int count = 0;
    // for (int i = 0; i < 32; ++i) {
    //     if (n & 1) {
    //         ++count;
    //     }
    //     n >>= 1;
    // }

    // 法2 末尾为1时, 减1后为0; 末尾不为1时, 减1后为连续的1, 一直到借位的1
    // 例:
    //     20 -> 0 0 0 1 0 1 0 0
    //     19 -> 0 0 0 1 0 0 1 1
    //      & -> 0 0 0 1 0 0 0 0
    // 所以 n &= (n-1) 消0的效率更高
    // while(n != 0) {
    //     n &= (n - 1);
    //     ++count;
    // }

    // 法3 整数的负数表示为n按位取反加1再补齐后的值
    //     20 -> 0 0 0 1 0 1 0 0
    //    -20 -> 1 1 1 0 1 1 0 0
    //      & -> 0 0 0 0 0 1 0 0 做与运算之后能得到最低位的1
    //      ^ -> 0 0 0 1 0 0 0 0 再做异或运算即将该位的1消除
    // while (n != 0) {
    //     n ^= (n & -n);
    //     ++count;
    // }
    // return count;

    // 法4 递归
    // return n == 0 ? 0 : hammingWeight(n & (n - 1)) + 1;
    return n == 0 ? 0 : hammingWeight(n ^ (n & -n)) + 1;
  }
};



