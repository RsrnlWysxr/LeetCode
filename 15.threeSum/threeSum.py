# -*- encoding: utf-8 -*-
""" 
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""

# nums中存在重复元素
# 时间复杂度：O(n^2)
# 空间复杂度: O(n)
# 未AC


class Solution1(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        self.num_to_count = {}

        for num in nums:
            # 在前表查询
            others = self._find_others(-num)
            for other in others:
                other.append(num)
                other.sort()
                if other not in ret:
                    ret.append(other)
            # 加入表
            self.num_to_count[num] = self.num_to_count.setdefault(num, 0) + 1

        return ret

    def _find_others(self, target):
        """
        在num_to_count中寻找两个数,其和为target
        返回[[]]
        """
        ret = []
        for k, v in self.num_to_count.items():
            if v != 0:
                self.num_to_count[k] -= 1   # 使用一次
                if self.num_to_count.get(target - k, 0) != 0:
                    ret.append([target - k, k])
                self.num_to_count[k] += 1   # 复原
        return ret

# 优化
# 充分利用和为0
# 排序后采用对撞指针


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums, r = sorted(nums), set()
        for i in [i for i in range(len(nums)-2) if i < 1 or nums[i] > nums[i-1]]:
            d = {-nums[i]-n: j for j, n in enumerate(nums[i + 1:])}
            r.update([(nums[i], n, -nums[i]-n)
                      for j, n in enumerate(nums[i+1:]) if n in d and d[n] > j])
        return list(map(list, r))


if __name__ == "__main__":
    Solution().threeSum([0, 0])
