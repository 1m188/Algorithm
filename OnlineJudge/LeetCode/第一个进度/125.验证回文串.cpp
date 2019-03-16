/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.39%)
 * Total Accepted:    26.6K
 * Total Submissions: 69.2K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        for (auto it = s.begin(); it < s.end();)
        {
            if (!isalnum(*it))
            {
                it = s.erase(it);
            }
            else
            {
                if (isalpha(*it) && isupper(*it))
                {
                    *it = tolower(*it);
                }
                it++;
            }
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};

#include "string"
using namespace std;
