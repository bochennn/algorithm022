/*
433. Minimum Genetic Mutation
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.


Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1


Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2


Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/
#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;


class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
    for (string& str : bank) {
        bank_set_.insert(str);
    }
    if (!bank_set_.count(end)) {
        return -1;
    }

    // min_steps_ = bank.size() + 2;
    // dfs(start, end, 0);
    // return min_steps_ == bank.size() + 2 ? -1 : min_steps_;

    // 双向bfs做法 套用自己做的模版:    
    int steps = 0;
    unordered_set<string> bfs_forward, bfs_backward;
    bfs_forward.insert(start);
    bfs_backward.insert(end);
    
    // 每次从一个方向推进一层
    while (!bfs_forward.empty() && !bfs_backward.empty()) {
        // 让较小的队列作为bfs对象
        if (bfs_forward.size() > bfs_backward.size()) {
            swap(bfs_forward, bfs_backward);
        }
        // 使用新的节点集合, 检查有效的分支
        unordered_set<string> new_forward;
        // 从forward方向遍历
        for (string element : bfs_forward) {
            // chage_state(element);
            for (int i = 0; i < element.size(); i++) {
                for (char& ch : gene) {
                    if (element[i] == ch) {
                        continue;
                    }
                    string make_element(element); // 省掉回溯
                    make_element[i] = ch;
                    if (bank_set_.count(make_element)) {
                        bank_set_.erase(make_element);
                        new_forward.insert(make_element);
                    }
                    if (bfs_backward.count(make_element)) {
                        return ++steps;
                    }
                }
            }
        }
        bfs_forward = new_forward; // 更新bfs队列
        steps++;
    }
    return -1;
  }
  // 现在的基因序列, 目标基因序列, 变异次数
  // void dfs(string& curr, string& end, int step) {
  //     // terminator
  //     if (curr == end) {
  //         min_steps_ = min(min_steps_, step);
  //         return;
  //     }
  //     // 当深度大于现有最小深度 || 已访问过当前序列时 返回
  //     if (step >= min_steps_ || bank_visited_[curr]) {
  //         return;
  //     }
  //     bank_visited_[curr] = 1;
  //     // 遍历当前的序列的每一个碱基对, 判断是否在bank中出现
  //     for (int i = 0; i < curr.size(); ++i) {
  //         char tmp = curr[i];
  //         for (char& ch : gene) {
  //             if (tmp == ch) {
  //                 continue;
  //             }
  //             curr[i] = ch;
  //             if (bank_map_.find(curr) != bank_map_.end()) {
  //                 dfs(curr, end, step + 1);
  //             }
  //         }
  //         curr[i] = tmp; // 回溯
  //     }
  // }
private:
  vector<char> gene = {'A', 'C', 'T', 'G'};
  int min_steps_;
  unordered_set<string> bank_set_;
  // unordered_map<string, int> bank_visited_;
};


Solution s_; 
TEST(CodeTest1, MinMutation) {
  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  EXPECT_EQ(2, s_.minMutation("AACCGGTT", "AAACGGTA", bank));
}

TEST(CodeTest2, MinMutation) {
  vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  EXPECT_EQ(3, s_.minMutation("AAAAACCC", "AACCCCCC", bank));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}