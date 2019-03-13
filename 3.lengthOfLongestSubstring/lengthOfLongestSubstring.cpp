
/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 记录了所有的不重复子串,略微麻烦
// 时间复杂度:O(n) 只需遍历一遍字符串
// 空间复杂度:O(1) 开辟的空间是一定的

class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string answer = {};              // 每一个不重复子串
        vector<string> answers = {};     // 所有不重复子串
        unordered_map<char, int> record;            // 字符-索引的哈希map
        for(int i = 0; i < s.size(); i++)
        {
            auto iter = record.find(s[i]);
            if (iter == record.end())
                answer.append(1, s[i]);
            else
            {
                answers.push_back(answer);
                int j = 0;
                while(answer[j] != s[i])
                    record.erase(answer[j++]);
                
                answer = s.substr(iter->second + 1, i - iter->second);
            }
            if (i == s.size() - 1)
                answers.push_back(answer);
            
            record[s[i]] = i;
        }
        int ret = 0;     
        for(const auto &substring : answers)
            ret = max(ret, (int)substring.length());

        return ret;
    }
};


class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> record(256, -1);     // 使用vecotr代替hashmap
        int ret = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++)
        {
            start = max(start, record[s[i]] + 1);
            ret = max(ret, i - start + 1);
            record[s[i]] = i;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abba";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
