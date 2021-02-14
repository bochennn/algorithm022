/*
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.
*/


class Solution {
public:
  int firstUniqChar(string s) {
    // unordered_map<char, int> char_map;
    // for (char& ch : s) {
    //   char_map[ch] += 1;
    // }
    vector<int> char_map(26, 0);
    for (char& ch : s) {
      char_map[ch - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (char_map[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};




