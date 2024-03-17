/*
 * @lc app=leetcode.cn id=3019 lang=csharp
 *
 * [3019] 按键变更的次数
 *
 * https://leetcode.cn/problems/number-of-changing-keys/description/
 *
 * algorithms
 * Easy (83.07%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 6.4K
 * Testcase Example:  '"aAbBcC"'
 *
 * 给你一个下标从 0 开始的字符串 s ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 s = "ab" 表示按键变更一次，而
 * s = "bBBb" 不存在按键变更。
 * 
 * 返回用户输入过程中按键变更的次数。
 * 
 * 注意：shift 或 caps lock 等修饰键不计入按键变更，也就是说，如果用户先输入字母 'a' 然后输入字母 'A' ，不算作按键变更。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aAbBcC"
 * 输出：2
 * 解释： 
 * 从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
 * 从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
 * 从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
 * 从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
 * 从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "AaAaAaaA"
 * 输出：0
 * 解释： 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s 仅由英文大写字母和小写字母组成。
 * 
 * 
 */

// @lc code=start
using System;
using System.Linq;

public class Solution
{
    public int CountKeyChanges(string s)
    {
        var li = s.ToList();
        for (int i = 0; i < li.Count; i++) // 先大写转小写
        {
            var c = li[i];
            if (char.IsUpper(c)) li[i] = char.ToLower(c);
        }

        int res = 0;
        for (int i = 1; i < li.Count; i++) // 然后判断是否存在连续的相同字符
        {
            if (li[i] != li[i - 1]) res++;
        }
        return res;
    }
}
// @lc code=end

