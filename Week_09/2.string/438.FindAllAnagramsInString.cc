/*
438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


class Solution {
public:
  bool checkAnagram(vector<int>& map_s, vector<int>& map_p) {
    if (map_s.size() != map_p.size()) {
      return false;
    }
    for (int i = 0; i < 26; i++) {
      if (map_s[i] != map_p[i]) {
        return false;
      }
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    // 滑动窗口
    int m = p.size(), n = s.size();
    vector<int> res;
    if (n < m) {
      return res;
    }
    // 初始化map
    vector<int> alphabet_s(26, 0), alphabet_p(26, 0);
    for (int i = 0; i < m; i++) {
      alphabet_s[s[i] - 'a'] += 1;
      alphabet_p[p[i] - 'a'] += 1;
    }
    // 在每次遍历的过程中,移出map中相应的字母,同时添加新的字母,然后与p对比
    for (int left = 0; left < n - (m - 1); left++) {
      if (left > 0) {
        alphabet_s[s[left-1] - 'a'] -= 1;
        alphabet_s[s[left+m-1] - 'a'] += 1;
      }

      if (checkAnagram(alphabet_s, alphabet_p)) {
        res.push_back(left);
      }
    }
    return res;
  }
};


