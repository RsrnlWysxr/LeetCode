""" 给定一个整数数组 nums 和一个目标值 target，
请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 """

""" 给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1] """


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        for i in range(len(nums)):
            subNum = target - nums[i]
            subNums = nums[i+1:]
            for j in range(len(subNums)):
                if subNums[j] == subNum:
                    ret.append(i)
                    ret.append(j + i + 1)
                    return ret
        return ret


if __name__ == "__main__":
    nums = [3, 2, 4]
    ret = Solution().twoSum(nums, 6)
    print(ret)
