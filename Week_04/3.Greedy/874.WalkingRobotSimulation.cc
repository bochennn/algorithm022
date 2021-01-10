/* 874. Walking Robot Simulation
[easy] [自己想比较难理解]
A robot on an infinite grid starts at point (0, 0) and faces north. The robot can receive one of three possible types of commands:

-2: turn left 90 degrees,
-1: turn right 90 degrees, or
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi).

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)



*/

class Solution {
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int coord[2] = {0, 0}; // x, y
    int direction = 1; // start from +y
    int facing = 1;

    set<pair<int, int>> obstacle_set;
    for (vector<int> obstacle: obstacles) {
      obstacle_set.insert(make_pair(obstacle[0], obstacle[1]));
    }

    int max_distance = 0;

    for (int& command : commands) {
      if (command > 0) {
        // 找该路线下是否有障碍物
        int goal[2] = {coord[0], coord[1]};
        // 做循环超时!
        // for (vector<int>& obstacle : obstacles) { // greedy尽可能走到最远
        // if (obstacle_map[direction^1].find(loc) != obstacle_map[direction].end()) {
        // 同一条路线内 && 障碍物距离比命令短
        // if (obstacle[direction ^ 1] == coord[direction ^ 1] &&
        //  if (facing * (obstacle_map[direction^1][loc] - coord[direction]) > 0 &&
        //      facing * (obstacle_map[direction^1][loc] - coord[direction]) <= command) {
        //     goal = obstacle_map[direction^1][loc] - facing * 1;
        //   }
        // }

        // coord[direction] = goal;
     
        for (int i = 0; i < command; ++i) {  // 时间O(N<commands>+K<obstacles>) 空间O(K)
          goal[direction] += facing * 1;
          // 从每一步位移坐标找障碍物比判断每个障碍物是否落在路线中要直接
          if (obstacle_set.find(make_pair(goal[0], goal[1])) == obstacle_set.end()) {
            coord[direction] = goal[direction];
            max_distance = 
                max(max_distance, coord[0] * coord[0] + coord[1] * coord[1]);
          } else {
            break;
          }
        }
      } else if (command == -1) {
        // turn right
        facing = direction ? facing : -facing; // 朝向南北时右转符号不变
        direction = direction ? 0 : 1;
      } else if (command == -2) {
        // turn left
        facing = direction ? -facing : facing;
        direction = direction ? 0 : 1;
      }
    }
    return max_distance;
  }
};
