
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // bool dfs(vector<int>& stones, int indx, int jump_size) {
    //     // 从当前石头向后遍历，过一遍队列到能跳到的石头
    //     // 时间复杂度O(3^n),每个递归下探3次
    //     for (int i = indx + 1; i < stones.size(); i++) {
    //         int gap = stones[i] - stones[indx];
    //         if (gap >= jump_size - 1 && gap <= jump_size + 1) {
    //             if (dfs(stones, i, gap)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return indx == stones.size() - 1;
    // }

    bool canCross(vector<int>& stones) {
        // return dfs(stones, 0, 0);
        // dp: 
        // 每一个石头记录从上一块石头跳过来的距离，因为可以从不同石头跳过来，距离可以是多个
        // dp[stones[i]][jumps] = dp[stones[j]][jumps-1] || 
        //                        dp[stones[j]][jumps] ||
        //                        dp[stones[j]][jumps+1]

        // unordered_map<int, int> pos;
        unordered_map<int, unordered_set<int>> dp;
        for (int& stone : stones) {
            dp[stone];
        }
        dp[0].insert(0);

        for (int i = 0; i < stones.size(); i++) {
            // 从该石头记录下来的距离
            for (auto& step : dp[stones[i]]) { // 表示跳到该位置
                for (int nstep = step - 1; nstep <= step + 1; nstep++) {
                    int target_pos = stones[i] + nstep; // 目标石头坐标
                    if (nstep > 0 && dp.count(target_pos)) { // 有这个石头时
                        dp[target_pos].insert(nstep);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};

