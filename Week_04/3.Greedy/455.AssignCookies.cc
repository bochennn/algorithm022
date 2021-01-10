/* 455. Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

*/

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    // 找出最多能满足几个孩子
    // 当s[j] >= g[i]时能满足 找出最小能满足的值为佳
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int indx = s.size() - 1;
    int res = 0;
    for (int i = g.size() - 1; i >= 0; i--) {
      // 当最大的饼干能满足胃口最大的孩子时才去找下一个
      if (indx >=0 && s[indx] >= g[i]) {
        res++;
        indx--;
      }
    }
    return res;

    // 或者小饼干先喂饱小胃口的
    // int index = 0;
    // for (int i = 0;i < s.size();++i) {
    //   if (index < g.size() && g[index] <= s[i]) {
    //     index++;
    //     res++;
    //   }
    // }

  }
};
