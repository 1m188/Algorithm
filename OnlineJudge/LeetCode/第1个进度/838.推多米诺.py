#
# @lc app=leetcode.cn id=838 lang=python3
#
# [838] 推多米诺
#
# https://leetcode-cn.com/problems/push-dominoes/description/
#
# algorithms
# Medium (55.32%)
# Likes:    267
# Dislikes: 0
# Total Accepted:    35.2K
# Total Submissions: 63.6K
# Testcase Example:  '"RR.L"'
#
# n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。
#
# 每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。
#
# 如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。
#
# 就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。
#
# 给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：
#
#
# dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
# dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
# dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
#
#
# 返回表示最终状态的字符串。
#
#
# 示例 1：
#
#
# 输入：dominoes = "RR.L"
# 输出："RR.L"
# 解释：第一张多米诺骨牌没有给第二张施加额外的力。
#
#
# 示例 2：
#
#
# 输入：dominoes = ".L.R...LR..L.."
# 输出："LL.RR.LLRRLL.."
#
#
#
#
# 提示：
#
#
# n == dominoes.length
# 1 <= n <= 10^5
# dominoes[i] 为 'L'、'R' 或 '.'
#
#
#


# @lc code=start
class Solution:

    def pushDominoes(self, dominoes: str) -> str:

        dl = list(dominoes)
        n = len(dl)
        f = True

        while f:
            f = False
            dlc = dl.copy()
            for i in range(n):
                if dl[i] == '.':
                    if i - 1 >= 0 and i + 1 < n:
                        if dl[i - 1] != 'R' and dl[i + 1] == 'L':
                            dlc[i] = 'L'
                            f = True
                        elif dl[i + 1] != 'L' and dl[i - 1] == 'R':
                            dlc[i] = 'R'
                            f = True
                    elif i - 1 >= 0:
                        if dl[i - 1] == 'R':
                            dlc[i] = 'R'
                            f = True
                    elif i + 1 < n:
                        if dl[i + 1] == 'L':
                            dlc[i] = 'L'
                            f = True
            dl = dlc

        return ''.join(dl)


# @lc code=end
