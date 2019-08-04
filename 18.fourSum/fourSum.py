# -*- encoding: utf-8 -*-
"""
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
"""

# 方法一:递归


class Solution1(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.res = []
        nums = sorted(nums)
        self.find_answers(4, nums, target, [])
        return self.res

    # 在nums中寻找count个数,其和为target, 将所选的数放入tmp_answer列表中
    def find_answers(self, count, nums, target, tmp_answer):
        # 返回条件
        if count == 1:
            for num in nums:
                if num == target:
                    tmp_answer.append(num)
                    self.res.append(tmp_answer[:])
                    return
            return

        used = []
        for index, num in enumerate(nums):
            if num in used:
                continue

            tmp_answer.append(num)
            used.append(num)
            self.find_answers(count - 1, nums[index + 1:], target - num,
                              tmp_answer[:])
            tmp_answer.pop()

        return


# 方法2: 优化


class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """


if __name__ == "__main__":
    nums = [1, 0, -1, 0, -2, 2]
    res = Solution().fourSum(nums, 0)
    print(res)