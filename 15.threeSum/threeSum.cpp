/* 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
] */
#include "..Tool/Helper.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.front() > 0 || nums.back() < 0)
            return {};

        int size = nums.size();
        vector<vector<int>> ret;

        for (int i = 0; i < size; ++i)
        {
            int target = -nums[i];
            if (target < 0)
                break; // 剪枝
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // 去重
            // 对撞指针
            int l = i + 1, r = size - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else
                {
                    // 处理重复
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }

        return ret;
    }
};
