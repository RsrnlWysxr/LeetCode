"""
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
"""

# 时间复杂度:O(n^2)


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size = len(nums)
        nums.sort()
        ret = sum(nums[:3])
        for i in range(size):
            l, r = i + 1, size - 1
            while l < r:
                tmp_sum = nums[i] + nums[l] + nums[r]
                if abs(tmp_sum - target) < abs(ret - target):
                    ret = tmp_sum
                if tmp_sum < target:
                    l += 1
                elif tmp_sum > target:
                    r -= 1
                else:
                    return ret
        return ret


if __name__ == "__main__":
    print(Solution().threeSumClosest([1,2,4,8,16,32,64,128], 82))
