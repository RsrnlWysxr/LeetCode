#include <iostream>
#include "../Tools/ListNode.h"
/* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* p1 = l1;      // 遍历l1
        ListNode* p2 = l2;      // 遍历l2
        ListNode* ret = new ListNode(0);       // 返回链表的虚拟头结点
        ListNode* curr = ret;      // 所操作的节点的前一个节点
        int carry = 0;          // 进位
        while(p1 != nullptr || p2 != nullptr || carry != 0)
        {
            int x = (p1 != nullptr) ? p1->val : 0;
            int y = (p2 != nullptr) ? p2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            /*更新所有链表的节点*/
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
            curr = curr->next;
        }
        return ret->next;
    }
};