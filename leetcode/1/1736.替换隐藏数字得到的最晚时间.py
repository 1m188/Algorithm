#
# @lc app=leetcode.cn id=1736 lang=python3
#
# [1736] 替换隐藏数字得到的最晚时间
#
# https://leetcode.cn/problems/latest-time-by-replacing-hidden-digits/description/
#
# algorithms
# Easy (44.44%)
# Likes:    74
# Dislikes: 0
# Total Accepted:    34.9K
# Total Submissions: 78.5K
# Testcase Example:  '"2?:?0"'
#
# 给你一个字符串 time ，格式为  hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。
#
# 有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
#
# 替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
#
#
#
# 示例 1：
#
#
# 输入：time = "2?:?0"
# 输出："23:50"
# 解释：以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
#
#
# 示例 2：
#
#
# 输入：time = "0?:3?"
# 输出："09:39"
#
#
# 示例 3：
#
#
# 输入：time = "1?:22"
# 输出："19:22"
#
#
#
#
# 提示：
#
#
# time 的格式为 hh:mm
# 题目数据保证你可以由输入的字符串生成有效的时间
#
#
#


# @lc code=start
class Solution:

    def maximumTime(self, time: str) -> str:

        hh, mm = time.split(':')

        if mm[1] == '?':
            mm = mm[0] + '9'
        if mm[0] == '?':
            mm = '5' + mm[1]

        if hh[0] == hh[1] == '?':
            hh = '23'
        elif hh[1] == '?':
            if int(hh[0]) <= 1: hh = hh[0] + '9'
            else: hh = hh[0] + '3'
        elif hh[0] == '?':
            if int(hh[1]) <= 3: hh = '2' + hh[1]
            else: hh = '1' + hh[1]

        return f'{hh}:{mm}'


# @lc code=end
