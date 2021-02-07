/*
1122. Relative Sort Array
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.


Example 1:


Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // 法1 自定义排序
    // unordered_map<int, int> rank;
    // int n = arr2.size();
    // for (int i = 0; i < n; ++i) {
    //   rank[arr2[i]] = i - n;
    // }
    // sort(arr1.begin(), arr1.end(), 
    //     [&](int x, int y) {
    //       return (rank.count(x) ? rank[x] : x) < (rank.count(y) ? rank[y] : y);
    //     });
    // return arr1;
    
    // 法2 计数排序
    int upper = *max_element(arr1.begin(), arr1.end());
    vector<int> frequency(upper + 1);
    for (int x: arr1) {
      ++frequency[x];
    }
    vector<int> ans;
    for (int x: arr2) {
      for (int i = 0; i < frequency[x]; ++i) {
        ans.push_back(x);
      }
      frequency[x] = 0;
    }
    for (int x = 0; x <= upper; ++x) {
      for (int i = 0; i < frequency[x]; ++i) {
        ans.push_back(x);
      }
    }
    return ans;
  }
};



