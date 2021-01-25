/*
 * [127] 单词接龙
 */
#include <gtest/gtest.h>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 构造字典集
        unordered_set<string> word_list_;
        for (string& word : wordList) {
            word_list_.insert(word); // 认为不存在重复单词
        }
        // 构造字母集
        vector<char> char_list_;
        for (int i = 0; i < 26; i++) {
            char_list_.emplace_back('a' + i);
        }

        unordered_set<string> bfs_forward; // !双向BFS, 每一次让较小的queue遍历
        bfs_forward.insert(beginWord);
        unordered_set<string> bfs_backward;
        bfs_backward.insert(endWord);

        int res = 1;

        // 对当前word改变其中一个字母,看是否在word list中存在
        while (!bfs_forward.empty() && !bfs_backward.empty()) {
            // 让较小的队列作为bfs对象
            if (bfs_forward.size() > bfs_backward.size()) {
                unordered_set<string> temp_set = bfs_forward;
                bfs_forward = bfs_backward;
                bfs_backward = temp_set;
            }

            unordered_set<string> new_forward;
            for (string current_word : bfs_forward) {
              // 假设字母数一样
              for (int i = 0; i < current_word.size(); i++) { // O(M<list>K<26char>)
                for (char& letter : char_list_) {
                  if (letter != current_word[i]) {
                    string makeWord(current_word); // 省掉回溯
                    makeWord[i] = letter;
                    if (word_list_.find(makeWord) != word_list_.end()) {
                      word_list_.erase(makeWord);
                      new_forward.insert(makeWord);
                    }
                    if (bfs_backward.find(makeWord) != bfs_backward.end()) {
                      return res+1;
                    }
                  }
                }
              }
            }
            bfs_forward = new_forward;
            res++;
        }
        return 0;
    }
};

Solution s_; 
TEST(CodeTest1, LadderLength) {
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
  EXPECT_EQ(5, s_.ladderLength("hit", "cog", wordList));
}

TEST(CodeTest2, LadderLength) {
  vector<string> wordList = {"a", "b", "c"};
  EXPECT_EQ(2, s_.ladderLength("a", "c", wordList));
}

TEST(CodeTest3, LadderLength) {
  vector<string> wordList = {"most","mist","miss","lost","fist","fish"};
  EXPECT_EQ(4, s_.ladderLength("lost", "miss", wordList));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

