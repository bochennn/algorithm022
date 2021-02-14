/*

*/


class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int indx = 0; // 字符处理的进度, 遇到非空格向前进, 完成一个完整的单词后添加一个空格
    // 原string因为有多重空格, 所以遍历进度<=未被改写的位置,所以可以在原string上操作
    for (int start = 0; start < s.size(); start++) {
      // 一个翻转单词的开始, 遍历到单词末尾
      if (s[start] != ' ') {
        if (indx != 0) {
          s[indx++] = ' ';
        }

        int end = start;
        while (end < s.size() && s[end] != ' ') {
          s[indx++] = s[end++];
        }
        // 截取该段单词翻转
        reverse(s.begin() + indx - (end - start), s.begin() + indx);
        start = end; // 空格的位置
      }
    }
    s.erase(s.begin() + indx, s.end());
    return s;
  }
};

