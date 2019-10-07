""" 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

输入: 123
输出: 321

输入: 120
输出: 21

输入: -123
输出: -321  """


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        x_str = str(x)
        ret = ''
        if x_str[0] == '-':
            ret += '-'
        ret += x_str[-1::-1].rstrip('-')
        ret = int(ret)
        if -2**31 < ret < 2**31 - 1:
            return ret
        return 0
