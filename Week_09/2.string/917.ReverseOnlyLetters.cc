/*
917. Reverse Only Letters
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/


class Solution {
public:
  string reverseOnlyLetters(string S) {
    int lo = 0, hi = S.size() - 1;

    while (lo < hi) {
      while (lo < hi && (S[lo] > 'z' || S[lo] < 'a') && (S[lo] > 'Z' || S[lo] < 'A')) {
        lo++;
      }
      while (hi > lo && (S[hi] > 'z' || S[hi] < 'a') && (S[hi] > 'Z' || S[hi] < 'A')) {
        hi--;
      }
      swap(S[lo++], S[hi--]);
    }
    return S;
  }
};


// 7_28]

