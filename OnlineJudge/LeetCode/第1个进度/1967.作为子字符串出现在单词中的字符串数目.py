#
# @lc app=leetcode.cn id=1967 lang=python3
#
# [1967] 作为子字符串出现在单词中的字符串数目
#
# https://leetcode-cn.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/
#
# algorithms
# Easy (78.75%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    8.3K
# Total Submissions: 10.5K
# Testcase Example:  '["a","abc","bc","d"]\n"abc"'
#
# 给你一个字符串数组 patterns 和一个字符串 word ，统计 patterns 中有多少个字符串是 word 的子字符串。返回字符串数目。
#
# 子字符串 是字符串中的一个连续字符序列。
#
#
#
# 示例 1：
#
#
# 输入：patterns = ["a","abc","bc","d"], word = "abc"
# 输出：3
# 解释：
# - "a" 是 "abc" 的子字符串。
# - "abc" 是 "abc" 的子字符串。
# - "bc" 是 "abc" 的子字符串。
# - "d" 不是 "abc" 的子字符串。
# patterns 中有 3 个字符串作为子字符串出现在 word 中。
#
#
# 示例 2：
#
#
# 输入：patterns = ["a","b","c"], word = "aaaaabbbbb"
# 输出：2
# 解释：
# - "a" 是 "aaaaabbbbb" 的子字符串。
# - "b" 是 "aaaaabbbbb" 的子字符串。
# - "c" 不是 "aaaaabbbbb" 的字符串。
# patterns 中有 2 个字符串作为子字符串出现在 word 中。
#
#
# 示例 3：
#
#
# 输入：patterns = ["a","a","a"], word = "ab"
# 输出：3
# 解释：patterns 中的每个字符串都作为子字符串出现在 word "ab" 中。
#
#
#
#
# 提示：
#
#
# 1 <= patterns.length <= 100
# 1 <= patterns[i].length <= 100
# 1 <= word.length <= 100
# patterns[i] 和 word 由小写英文字母组成
#
#
#

from typing import List


# @lc code=start
class Solution:

    def numOfStrings(self, patterns: List[str], word: str) -> int:

        res = 0
        for w in patterns:
            if w in word: res += 1
        return res


# @lc code=end
