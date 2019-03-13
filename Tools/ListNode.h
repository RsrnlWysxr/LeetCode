#ifndef __LISTNODE
#define __LISTNODE

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

#endif