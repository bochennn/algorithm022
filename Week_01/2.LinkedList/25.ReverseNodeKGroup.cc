/*
25. Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]


Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k < 1) {
      return head;
    }
        
    // 截取k个连续节点, 进行整体翻转, 让head指向node(k+1)
    // new_head是前k个节点的末尾
    ListNode* tail = head;
    for (int i = 0; i < k; i++) {
      if (tail == nullptr) {
        return head;
      }
      tail = tail->next;
    }
        
    // 假定得到的list node是已经翻转好的末尾, node头是pre
    ListNode* pre = reverseKGroup(tail, k);
    // 找到k group的头和尾了, 将它们翻转后指向余下来list的头
    ListNode* cur = head;
    while (cur != tail) {
      ListNode* temp = cur->next;
      cur->next = pre;
      pre = cur; // 双指针向下个节点移动
      cur = temp;
    }
    return pre; // cur已经指向tail了, 而tail时下个k group的头
  }
};

