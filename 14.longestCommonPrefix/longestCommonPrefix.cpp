/* 
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

输入: ["flower","flow","flight"]
输出: "fl"
*/

#include "..Tools/Helper.h"

// 按列处理
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0].at(i);
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size() || c != strs[j].at(i))
                {
                    return strs[0].substr(0, i);        // i == 0 return “”
                }
            }
        }
        return strs[0];
    }
};