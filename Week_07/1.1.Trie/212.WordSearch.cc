/*
212. Word Search II
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


Example 1:

Input: board = [{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}], words = {'oath','pea','eat','rain'}
Output: {'eat','oath'}

Example 2:

Input: board = [{'a','b'},{'c','d'}], words = {'abcb'}
Output: []

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

*/
#include <gtest/gtest.h>
using namespace std;

class Trie {
 public:
  Trie() = default;

  void Insert(const string& word) {
    Trie* root = this;
    for (const char& ch : word) {
      if (root->next_.find(ch) == root->next_.end()) {
        root->next_[ch] = new Trie();
      }
      root = root->next_[ch];
    }
    root->string_end_ = true;
  }

  bool Search(const string& word) {
    Trie* root = this;
    for (const char& ch : word) {
      if (root->next_.find(ch) == root->next_.end()) {
        return false;
      }
      root = root->next_[ch];
    }
    return root->string_end_;
  }

  bool StartsWith(const char& ch) {
    if (this->next_.find(ch) == this->next_.end()) {
      return false;
    }
    return true;
  }

  // ------------------------------
  bool StringEnd() const {
    return string_end_;
  }

  void SetStringEnd(const bool string_end) {
    string_end_ = string_end;
  }
  // ------------------------------
  Trie* Next(const char& ch) {
      return this->next_[ch];
  }

 private:
  bool string_end_ = false;
  map<char, Trie*> next_;
};


class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // Trie复杂度分析: 首先整个board会遍历O(m*m), 每个单词向下做dfs下探,设键长l, 每次下探找前缀的复杂度为1
    // 时间复杂度O(m*m*l)
    
    vector<string> res;
    number_of_words_ = words.size();

    board_rows_ = board.size();
    if (board_rows_ < 1) {
      return res;
    }
    board_cols_ = board[0].size();
    visited_.assign(board_rows_, vector<bool>(board_cols_, false));

    Trie* trie = new Trie();
    for (string& word : words) {
      trie->Insert(word);
    }

    string candidate;
    for (int row = 0; row < board_rows_; row++) {
        for (int col = 0; col < board_cols_; col++) {
            dfs(board, res, row, col, 1, trie, candidate);
        }
    }
    return res;
  }

  // 从每一个词开始下探
  void dfs(vector<vector<char>>& board, vector<string>& res,
           int row, int col, int depth, Trie* node, string& word) {
    // **terminator**
    if (depth > word_length_) { // 搜索深度限制
      return;
    }
    if (number_of_words_ == 0) {
      return;
    }
    if (row < 0 || row >= board_rows_ || col < 0 || col >= board_cols_) {
      return;
    }
    if (visited_[row][col]) {
      return;
    }

    if (!node->StartsWith(board[row][col])) {
      return;
    }
    
    const char& candidate = board[row][col];
    word += candidate;
    Trie* curr_node = node->Next(candidate);

    visited_[row][col] = true;

    if (curr_node->StringEnd()) {
      curr_node->SetStringEnd(false); // 该节点将不再是单词尾
      res.emplace_back(word);

      number_of_words_--;
      // if (node->StringEnd()) { // 剪枝
      // return;
      // }
    }

    dfs(board, res, row + 1, col, depth + 1, curr_node, word);
    dfs(board, res, row - 1, col, depth + 1, curr_node, word);
    dfs(board, res, row, col + 1, depth + 1, curr_node, word);
    dfs(board, res, row, col - 1, depth + 1, curr_node, word);

    // 回溯
    word.pop_back();
    visited_[row][col] = false;
  }

 private:
  static const int word_length_ = 10;
  int number_of_words_;

  int board_cols_, board_rows_;

  vector<vector<bool>> visited_;
};


Solution s_;
TEST(CodeTest1, WordSearch) {
  vector<vector<char>> board{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
  vector<string> words{"oath","pea","eat","rain"};
  vector<string> ans{"oath","eat"};
  EXPECT_EQ(ans, s_.findWords(board, words));
}

TEST(CodeTest2, WordSearch) {
  vector<vector<char>> board{{'a'}};
  vector<string> words{"ab"};
  vector<string> ans;
  EXPECT_EQ(ans, s_.findWords(board, words));
}

TEST(CodeTest3, WordSearch) {
  vector<vector<char>> board{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
  vector<string> words{"oath","pea","eat","rain","oathi","oathk","oathf","oate","oathii","oathfi","oathfii"};
  vector<string> ans{"oath", "oathf", "oathfi", "oathfii", "oathk", "oathi", "oathii", "oate", "eat"};
  EXPECT_EQ(ans, s_.findWords(board, words));
}

TEST(CodeTest4, WordSearch) {
  vector<vector<char>> board{{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'}};
  vector<string> words{{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}};
  vector<string> ans{{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}};
  EXPECT_EQ(ans, s_.findWords(board, words));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
