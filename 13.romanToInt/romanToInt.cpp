/* 
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
 */

class Solution
{
public:
    Solution()
    {
        hash = unordered_map<string, int>{
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}};
    }
    int romanToInt(string s)
    {
        int retNum = 0;
        int index = 0; // 记录字符串索引位置
        while (index != s.length())
        {
            if (s.length() - index < 2)
            {
                auto fragment = hash.find(s.substr(index, 1));
                retNum += fragment->second;
                index++;
            }
            else
            {
                auto fragment = hash.find(s.substr(index, 2));
                if (fragment != hash.end())
                {
                    retNum += fragment->second;
                    index += 2;
                }
                else
                {
                    retNum += hash[s.substr(index, 1)];
                    index += 1;
                }
            }
        }
        return retNum;
    }

private:
    unordered_map<string, int> hash;
};