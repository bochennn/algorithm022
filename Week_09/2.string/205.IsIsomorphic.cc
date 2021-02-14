/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/


class Solution {
public:
  bool isIsomorphic(string s, string t) {
    // 双哈希
    unordered_map<char, char> s2t, t2s;

    for (int i = 0; i < s.size(); ++i) {
      char x = s[i], y = t[i];
      // 其实不需要去统计字符出现的次数
      if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
        return false;
      }
      s2t[x] = y;
      t2s[y] = x;
    }
    return true;
  }
};

