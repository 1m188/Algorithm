#
# @lc app=leetcode.cn id=2549 lang=python3
#
# [2549] 统计桌面上的不同数字
#
# https://leetcode.cn/problems/count-distinct-numbers-on-board/description/
#
# algorithms
# Easy (63.32%)
# Likes:    18
# Dislikes: 0
# Total Accepted:    8K
# Total Submissions: 12.6K
# Testcase Example:  '5'
#
# 给你一个正整数 n ，开始时，它放在桌面上。在 10^9 天内，每天都要执行下述步骤：
#
#
# 对于出现在桌面上的每个数字 x ，找出符合 1 <= i <= n 且满足 x % i == 1 的所有数字 i 。
# 然后，将这些数字放在桌面上。
#
#
# 返回在 10^9 天之后，出现在桌面上的 不同 整数的数目。
#
# 注意：
#
#
# 一旦数字放在桌面上，则会一直保留直到结束。
# % 表示取余运算。例如，14 % 3 等于 2 。
#
#
#
#
# 示例 1：
#
#
# 输入：n = 5
# 输出：4
# 解释：最开始，5 在桌面上。
# 第二天，2 和 4 也出现在桌面上，因为 5 % 2 == 1 且 5 % 4 == 1 。
# 再过一天 3 也出现在桌面上，因为 4 % 3 == 1 。
# 在十亿天结束时，桌面上的不同数字有 2 、3 、4 、5 。
#
#
# 示例 2：
#
#
# 输入：n = 3
# 输出：2
# 解释：
# 因为 3 % 2 == 1 ，2 也出现在桌面上。
# 在十亿天结束时，桌面上的不同数字只有两个：2 和 3 。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 100
#
#
#


# @lc code=start
class Solution:
    '''
    
    观察到，时间充分大时，对于数n，总有n-1个数会出现
    
    '''

    def distinctIntegers(self, n: int) -> int:

        if n == 1: return 1
        return n - 1


# @lc code=end
