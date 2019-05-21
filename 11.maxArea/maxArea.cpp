#include "../Tools/Helper.h"

class Solution
{
public:
    Solution()
    {
        // heightVec = new vector<int>();
    }

    int maxArea(vector<int> &height)
    {
        heightVec = height;
        int left = 0, right = height.size() - 1,
            ret = 0;
        while (right > left)
        {
            int areaTemp = CalculatingArea(right, left);
            ret = areaTemp > ret ? areaTemp : ret;

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }

private:
    int CalculatingArea(int right, int left)
    {
        return min(heightVec[left], heightVec[right]) * (right - left);
    }

private:
    vector<int> heightVec;
};