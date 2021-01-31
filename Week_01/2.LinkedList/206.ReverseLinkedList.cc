/*
206. Reverse Linked List
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    // 定义pre和cur, pre在前cur在后 
    // 每次将pre->next指向cur, 实现一个局部翻转
    // 翻转完之后两个指针同时向前移

    ListNode* cur = NULL, * pre = head;
    while (pre != NULL) {
      ListNode* tmp = pre->next;
      pre->next = cur;
      cur = pre;
      pre = tmp;
    }
    return cur;
  }

  ListNode* reverseList(ListNode* head) {
    // 递归形式
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode* cur = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return cur;
  }
};

