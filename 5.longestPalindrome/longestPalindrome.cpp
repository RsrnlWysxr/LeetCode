/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。 */


#include <string>
#include <vector>

using namespace std;

/* 
暴力破解
时间复杂度：O(n^3)
空间复杂度：O(1) */

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string ret = "";
        for(int i = 0; i < s.size(); i++)
        {
            // s[i...j]
            for(int j = i; j < s.size(); j++)
            {
                string tmp = s.substr(i, j - i + 1);
                if(isPalindrome(tmp) && ret.size() < tmp.size())
                    ret = tmp;
            }
        }
        return ret;
    }
    
    private:
    bool isPalindrome(const string& s)
    {
        int l = 0,
            r = s.size()-1;
        while(l < r && s[l] == s[r])
            l++,r--;
        return l >= r ? true : false;
    }
};

/*
优化验证是否为回文的部分
使用动态规划的思路，先完成1字符和2字符的回文验证，
之后通过查表验证是否回文
P[i,j]表示s[i...j]前闭后闭区间内是否为回文串
P[i,j] = P[i+1,j-1] && s[i] = s[j]
时间复杂度：O(n^2)
空间复杂度：O(n^2)
*/
// 
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string ret = "";
        int length = s.size();
        vector<vector<bool>> p(length, vector<bool>(length, false));
        // 初始化1字符和2字符的回文验证
        for (int i = 0; i < length; i++)
        {
            p[i][i] = true;
            if (ret.size() < 2)
                ret = s[i];
            if (i + 1 < length && s[i] == s[i + 1])
            {
                p[i][i + 1] = true;
                ret = s.substr(i, 2);
            }
        }
        // 按长度的顺序依次填充查询表
        for (int i = 2; i < length; i++)
        {
            // i代表偏移，i+1代表回文串长度
            for (int j = 0; j < length; j++)
            {
                if (j + i < length && p[j + 1][j + i - 1] && s[j] == s[j + i])
                {
                    p[j][j + i] = true;
                    if (ret.size() < i + 1)
                        ret = s.substr(j, i + 1);
                }
            }
        }
        return ret;
    }
};

/* 中心拓展，有2n-1个中心（考虑奇偶）
从中心向两侧拓展
时间复杂度：O(n^2)
空间复杂度：O(1)
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int istart = 0, iend = 0; // 返回的回文字符串[start, end)
        for (int i = 0; i < s.length(); i++)
        {
            int ioddLen = expandAroundCenter(s, i, i);      // 为奇数，则当前字符为左右拓展起点
            int ievenLen = expandAroundCenter(s, i, i + 1); // 为偶数，则当前字符为左拓展起始
            int irealLen = max(ioddLen, ievenLen);
            if (irealLen > iend - istart)
            {
                istart = i - (irealLen - 1) / 2;
                iend = i + irealLen / 2;
            }
        }
        return s.substr(istart, iend - istart);
    }

private:
    /*传入字符串，以及左右开始拓展位置，
      返回回文长度*/
    int expandAroundCenter(string &s, int ileft, int iright)
    {
        while (ileft >= 0 && iright < s.length() && s[ileft] == s[iright])
            ileft--, iright++;
        return iright - ileft - 1;
    }
};