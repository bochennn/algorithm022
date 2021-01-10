class Solution {
public:
  // 现在的基因序列, 目标基因序列, 变异次数
  void dfs(string& curr, string& end, int step) {
    // terminator
    if (curr == end) {
      min_steps_ = min(min_steps_, step);
      return;
    }
    // 当深度大于现有最小深度 || 已访问过当前序列时 返回
    if (step >= min_steps_ || bank_visited_[curr]) {
      return;
    }
    bank_visited_[curr] = 1;
    // 遍历当前的序列的每一个碱基对, 判断是否在bank中出现
    for (int i = 0; i < curr.size(); ++i) {
      char tmp = curr[i];
      for (char& ch : gene) {
        if (tmp == ch) {
          continue;
        }
        curr[i] = ch;
        if (bank_map_.find(curr) != bank_map_.end()) {
          dfs(curr, end, step + 1);
        }
      }
      curr[i] = tmp; // 回溯
    }
  }

  int minMutation(string start, string end, vector<string>& bank) {
    for (string& str : bank) {
      bank_map_[str]++;
    }
    if (!bank_map_[end]) {
      return -1;
    }
    min_steps_ = bank.size() + 2;
    dfs(start, end, 0);
    return min_steps_ == bank.size() + 2 ? -1 : min_steps_;
  }
private:
  vector<char> gene = {'A', 'C', 'T', 'G'};
  int min_steps_;
  unordered_map<string, int> bank_map_;
  unordered_map<string, int> bank_visited_;
};
