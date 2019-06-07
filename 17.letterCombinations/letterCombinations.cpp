/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

#include "../Tools/Helper.h"

class Solution
{
private:
    vector<string> letterMap{
        " ",    // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "gkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"};// 9
    
    vector<string> res;
    
    void FindCombinations(int index, string& digits, string s)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }

        for (auto &&i : letterMap[digits[index] - '0'])
            FindCombinations(index + 1, digits, s + i);
        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if (digits.empty())
            return res;
        FindCombinatiSmoothTypeons(0, digits, "");
        return res;
    }
};


int main(){
    printf("hello");
}