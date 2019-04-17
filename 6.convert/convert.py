""" 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN" """

# 按行排序,思路在于沿着Z的形状进行排序
# list<string>


class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        record_list = ["" for x in range(0, min(numRows, len(s)))]
        cur_row_int = 0
        godown_bool = False
        for c in s:
            record_list[cur_row_int] += c
            if cur_row_int in [0, numRows - 1]:
                godown_bool = not godown_bool
            cur_row_int += 1 if godown_bool else -1

        ret = ""
        for s in record_list:
            ret += s

        return ret
