""" 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。 """

""" 优化验证是否为回文的部分
使用动态规划的思路，先完成1字符和2字符的回文验证，
之后通过查表验证是否回文
P[i,j]表示s[i...j]前闭后闭区间内是否为回文串
P[i,j] = P[i+1,j-1] && s[i] = s[j]
时间复杂度：O(n^2)
空间复杂度：O(n^2) """


class Solution1(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ret = ''
        length = len(s)
        p = [[False for x in range(0, length)] for y in range(0, length)]
        # 初始化1字符和2字符的回文验证
        for i in range(0, length):
            p[i][i] = True
            if len(ret) < 2:
                ret = s[i]
            if (i + 1 < length) and (s[i] == s[i+1]):
                p[i][i+1] = True
                ret = s[i:i+2]
        # 按长度的顺序依次填充查询表
        for i in range(2, length):
            # i代表偏移， i+1代表回文串长度
            for j in range(0, length):
                if j + i < length and p[j + 1][j + i - 1] and s[j] == s[j + i]:
                    p[j][j + i] = True
                    if len(ret) < i + 1:
                        ret = s[j: j + i + 1]
        return ret


""" 
中心拓展，有2n-1个中心（考虑奇偶）
从中心向两侧拓展
时间复杂度：O(n^2)
空间复杂度：O(1)
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return ""
        start_i = 0
        end_i = 0
        for i in range(0, len(s)):
            oddlen_i = self.__expand_around_center(s, i, i)
            evenlen_i = self.__expand_around_center(s, i, i + 1)
            len_i = max(oddlen_i, evenlen_i)
            if len_i > end_i - start_i:
               start_i = i - (len_i - 1) / 2
               end_i = i + len_i / 2
        return s[start_i : end_i + 1]

    def __expand_around_center(self, s, left_i, right_i):
        while left_i >= 0 and right_i < len(s) and s[left_i] == s[right_i]:
            left_i -= 1
            right_i += 1
        return right_i - left_i - 1