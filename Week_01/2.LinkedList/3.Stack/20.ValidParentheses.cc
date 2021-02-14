/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> parentheses;
    parentheses['('] = ')';
    parentheses['['] = ']';
    parentheses['{'] = '}';

    if (s.size() < 2) {
      return false;
    }
    stk.push(parentheses[s[0]]);

    for (int i = 1; i < s.size(); i++) {
      if (!stk.empty() && stk.top() == s[i]) {
        stk.pop();
      } else {
        stk.push(parentheses[s[i]]);
      }
    }
    return stk.empty();
  }
};



