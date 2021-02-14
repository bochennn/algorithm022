/*
8. String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

1.Read in and ignore any leading whitespace.
2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3.Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5.If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
6.Return the integer as the final result.

Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

*/


class Solution {
public:
  int myAtoi(string s) {
    long res = 0;
    int sign = 0;

    for (int indx = 0; indx < s.size(); indx++) {
      if (res == 0 && s[indx] == ' ') {
        if (sign) break;
        continue;
      } else if (res == 0 && s[indx] == '+') {
        if (sign) break;
        sign = 1;
      } else if (res == 0 && s[indx] == '-') {
        if (sign) break;
        sign = 2;
      } else if (res == 0 && s[indx] == '0') {
        sign = sign ? sign : 1;
      } else if (s[indx] >= '0' && s[indx] <= '9') {
        res = res * 10 + (s[indx] - '0');
        if (sign < 2 && res > INT_MAX) { // positive
          return INT_MAX;
        } else if (sign == 2 && -res < INT_MIN) { // negative
          return INT_MIN;
        }
      } else {
        break;
      }
    }
    return static_cast<int>(sign == 2 ? -res : res);
  }
};


