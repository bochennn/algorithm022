/*
208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true


Your Trie object will be instantiated and called as such:
Trie* obj = new Trie();
obj->insert(word);
bool param_2 = obj->search(word);
bool param_3 = obj->startsWith(prefix);
*/
#include <gtest/gtest.h>
using namespace std;

// 抄答案
class Trie1 {
 public:
  Trie1() {};

  void insert(const string& word) {
    Trie1* root = this;
    for (const auto& ch : word) {
      if (root->next[ch - 'a'] == nullptr) {
        root->next[ch - 'a'] = new Trie1(); // 每层放一个字
      }
      root = root->next[ch - 'a'];
    }
    root->is_string = true;
  }

  bool search (const string& word) {
    Trie1* root = this;
    for (const auto& ch : word) {
      if (root->next[ch - 'a'] == nullptr) {
        return false;
      }
      root = root->next[ch - 'a'];
    }
    return root->is_string; // 确认该root已经在叶子节点
  }

  bool startsWith(const string& prefix) {
    Trie1* root = this;
    for (const auto& p : prefix) {
      if (root->next[p - 'a'] == nullptr) {
        return false;
      }
      root = root->next[p - 'a']; // 向下遍历
    }
    return true; // 已经是相同的词了
  }

 private:
  bool is_string = false;
  Trie1* next[26] = { nullptr }; // 26叉树 按数组存放, 空间有限且固定
};

// 改写
class Trie2 {
 public:
  Trie2() = default;

  void insert(const string& word) {
    Trie2* root = this;
    for (const auto& ch : word) {
      if (root->next_.find(ch) == root->next_.end()) {
        root->next_[ch] = new Trie2(); // 每层放一个字
      }
      root = root->next_[ch];
    }
    root->string_end_ = true;
  }

  bool search(const string& word) {
    return find(word);
  }

  bool startsWith(const string& prefix) {
    return find(prefix, false);
  }

 private:
  bool find(const string& word, bool exact_match=true) {
    Trie2* root = this;
    for (const auto& ch : word) {
      if (root->next_.find(ch) == root->next_.end()) {
        return false;
      }
      root = root->next_[ch]; // 向下遍历
    }
    return exact_match ? root->string_end_ : true;
  }

 private:
  bool string_end_ = false; // 确认该root已经在叶子节点
  map<char, Trie2*> next_;
};

// 课程模版
// 做word search的时候发现, 可能还是用定义的TrieNode好一点, 方便剪枝, 如果直接用自己去定义的话不太好回溯
class Trie3 {
  struct TrieNode { // 额外定义节点
    map<char, TrieNode*> child_table; // 子树集
    int end; // 该节点为单词的末尾
    TrieNode(): end(0) {}
  };
 public:
  Trie3() {
    root = new TrieNode(); 
  }

  void insert(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++) {
      if (curr->child_table.count(word[i]) == 0) {
        curr->child_table[word[i]] = new TrieNode();
      }
      curr = curr->child_table[word[i]];
    }
    curr->end = 1;
  }

  bool search(string word) {
    return find(word, 1);
  }

  bool startsWith(string prefix) {
    return find(prefix, 0);
  }

 private:
  TrieNode* root;
  bool find(string s, int exact_match) {
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); i++) {
      if (curr->child_table.count(s[i]) == 0) {
        return false;
      } else {
        curr = curr->child_table[s[i]];
      }
    }
    if (exact_match) {
      return (curr->end) ? true : false;
    } else {
      return true;
    }
  }
};


Trie1 t1_;
Trie2 t2_;
Trie3 t3_;

TEST(CodeTest1, ImplementTrie1) {
}

TEST(CodeTest2, ImplementTrie2) {
}

TEST(CodeTest2, ImplementTrie3) {
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

