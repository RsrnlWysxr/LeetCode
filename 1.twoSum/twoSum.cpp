#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* 问题的本质是查找,优化查找算法,即可以提高时间复杂度 */

/*
时间复杂度: O(n^2)
空间复杂度: O(1)
*/
class Solution1 
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

/*
时间复杂度: O(n)
空间复杂度: O(n)
*/
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hashMap;
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = hashMap.find(target - nums[i]);
            if (iter != hashMap.end()) 
                return vector<int>{iter->second, i};
            hashMap[nums[i]] = i;
        }
       return vector<int>();
    }
};