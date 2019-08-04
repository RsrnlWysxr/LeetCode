""" 
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。
"""


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# 方法一: 直接方法,遍历得到长度
class solution_1(object):
    def removenthfromend(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 验证head
        if head is None:
            return None
        # 获取长度
        p = head
        count = 0
        while p:
            p = p.next
            count += 1
        # 验证n
        if n > count:
            return None
        if n == count:
            return head.next
        # 计算倒数
        p = head
        for x in range(0, count - n - 1):
            p = p.next
        # 指在前一个
        p.next = p.next.next
        # 得到节点返回
        return head


# 方法二: 使用虚拟头节点加双指针
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 验证head
        if head is None:
            return None
        # 设置虚拟头节点
        p = ListNode(0)
        p.next = head
        # 双指针初始化, 到达待删除节点的前一个, 从虚拟头节点开始.
        f, b = p, p
        for i in range(n + 1):
            b = b.next
        # 移动到位置
        while b is not None:
            f = f.next
            b = b.next
        # 删除操作
        f.next = f.next.next
        return p.next
