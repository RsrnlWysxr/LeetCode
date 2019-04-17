/* 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN" */

#include <string>
#include <vector>

using namespace std;

/*按行访问,思路在于找规律
时间复杂度:O(n) n == len(s) 因为每个索引被访问了一次
空间复杂度:O(n) n == len(S) 因为每个索引存放一次
*/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<vector<int>> recordVec(numRows, vector<int>());
        int stepInt = 2 * numRows - 2;
        // 将Z的两|索引构建完成
        for (int i = 0; i < numRows; i++)
        {
            int indexInt = i;
            while (indexInt < s.length())
            {
                recordVec[i].push_back(indexInt);
                indexInt += stepInt;
            }
        }
        // 取最后一行每个数,循环最后一行的size
        for (int i = 0; i < recordVec[numRows - 1].size(); i++)
        {
            int startIndexInt = recordVec[numRows - 1][i];
            // 循环次数numRows - 2
            for (int j = numRows - 2; j > 0; j--)
            {
                auto insertIter = find(recordVec[j].begin(), recordVec[j].end(), j + (i + 1) * stepInt);
                if (++startIndexInt < s.length())
                    recordVec[j].insert(insertIter, startIndexInt);
            }
        }

        // Z字构建完成,读取字符串
        string retStr = "";
        for (auto &&vec : recordVec)
            for (auto &&index : vec)
                retStr += s[index];

        return retStr;
    }
};