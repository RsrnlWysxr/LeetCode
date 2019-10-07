
# 时间复杂度:O(n) 只遍历一遍字符串
# 空间复杂度:O(1) 空间开销固定

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        record = {}
        start, ret = 0, 0
        for i in range(len(s)):
            start = max(start, record.get(s[i], -1) + 1)
            ret = max(ret, i - start + 1)
            record[s[i]] = i
        return ret

# 对于record和start的理解:
# 记录所有字符到索引的映射, 但是start后的record才有效