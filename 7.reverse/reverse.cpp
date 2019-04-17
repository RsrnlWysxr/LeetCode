/* 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

输入: 123
输出: 321

输入: 120
输出: 21

输入: -123
输出: -321 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int retInt = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (retInt > INT_MAX/10 || (retInt == INT_MAX/10 && pop > 7)) return 0;
            if (retInt < INT_MIN/10 || (retInt == INT_MIN/10 && pop < -8)) return 0;
            retInt = retInt * 10 + pop;
        }
        return retInt;
    }
};