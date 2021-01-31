/*
142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.


Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

*/
#include <gtest/gtest.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    // 1. 哈希表, O(n)复杂度, 线性找重复的节点
    // unordered_set<ListNode*> list_map;
    // ListNode* pointer = head;
    // while (pointer != nullptr) {
    //   if (list_map.count(pointer)) {
    //     return pointer;
    //   }
    //   list_map.insert(pointer);
    //   pointer = pointer->next;
    // }
    // return nullptr;

    // 2. 快慢指针, 在环中相遇的时候, 计算其开始的位置
    // 定义环在x位置开始, 快慢指针在x+y处相遇, 环的长度为y+z
    // fast = x + n * (y + z) + y
    // slow = x + y
    // fast = 2 * slow
    // so, x + n * (y + z) + y = 2 * x + 2 * y
    // which is, n * (y + z) = x + y
    // we need y: y = (n - 1) * (y + z) + z
    // then y = z
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }
    ListNode* slow_pointer = head;
    ListNode* fast_pointer = head->next;

    while (fast_pointer != slow_pointer) {
      if (fast_pointer == nullptr || fast_pointer->next == nullptr) {
        return nullptr;
      }
      slow_pointer = slow_pointer->next;
      fast_pointer = fast_pointer->next->next;
    }
    fast_pointer = head;
    slow_pointer = slow_pointer->next;
    while (fast_pointer != slow_pointer) {
      fast_pointer = fast_pointer->next;
      slow_pointer = slow_pointer->next;
    }
    return fast_pointer;
}
};



