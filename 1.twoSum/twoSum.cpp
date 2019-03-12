#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;

        int len;
        len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int subNum;
            subNum = target - nums[i];
            for(int j = i + 1; j < len; j++)
            {
                if (subNum == nums[j])
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};