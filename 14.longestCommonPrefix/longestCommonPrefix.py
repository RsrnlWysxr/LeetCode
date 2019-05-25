""" 
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

输入: ["flower","flow","flight"]
输出: "fl"
"""


# 水平扫描
# 最坏情况：strs内所有字符串相同
# 引申：前面的字符串长，后面的字符串短的情况
class Solution(object):

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''

        common_prefix = strs[0]
        for single_str in strs:
            common_prefix = self._findCommonPrefix(common_prefix, single_str)
            if common_prefix == '':
                break

        return common_prefix

    def _findCommonPrefix(self, a, b):
        ret = ''
        for index in range(min(len(a), len(b))):
            if a[index] == b[index]:
                ret += a[index]
            else:
                return ret

        return ret


# 按列处理
# 假设最后一个字符串很短
class Solution1(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''

        ret = ''
        # 按列看
        zipped = zip(*strs)
        for col in zipped:
            if len(set(col)) == 1:
                ret += col[0]
            else:
                break
        
        return ret

# 分治
# 字典树

        
        


if __name__ == "__main__":
    Solution().longestCommonPrefix(['flow', 'flowss', 'flaasdf'])
