/* 
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */

#include "../Tools/Helper.h"

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int tmp_sum = nums[i] + nums[l] + nums[r];
                if (abs(tmp_sum - target) < abs(ret - target))
                    ret = tmp_sum;
                if (tmp_sum < target)
                    l++;
                else if (tmp_sum > target)
                    r--;
                else
                    return ret;
            }
        }
        return ret;
        
        
    }
};