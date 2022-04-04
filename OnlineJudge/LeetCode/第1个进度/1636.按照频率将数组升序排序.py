#
# @lc app=leetcode.cn id=1636 lang=python3
#
# [1636] 按照频率将数组升序排序
#
# https://leetcode-cn.com/problems/sort-array-by-increasing-frequency/description/
#
# algorithms
# Easy (69.82%)
# Likes:    40
# Dislikes: 0
# Total Accepted:    11.9K
# Total Submissions: 17.1K
# Testcase Example:  '[1,1,2,2,2,3]'
#
# 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。
#
# 请你返回排序后的数组。
#
#
#
# 示例 1：
#
# 输入：nums = [1,1,2,2,2,3]
# 输出：[3,1,1,2,2,2]
# 解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
#
#
# 示例 2：
#
# 输入：nums = [2,3,1,3,2]
# 输出：[1,3,3,2,2]
# 解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
#
#
# 示例 3：
#
# 输入：nums = [-1,1,-6,4,5,-6,1,4,1]
# 输出：[5,-1,4,4,-6,-6,1,1,1]
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# -100 <= nums[i] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:

    def frequencySort(self, nums: List[int]) -> List[int]:

        di = {}

        for i in nums:
            if i not in di:
                di[i] = 1
            else:
                di[i] += 1

        di = list(di.items())
        di.sort(key=lambda x: x[0], reverse=True)
        di.sort(key=lambda x: x[1])

        res = []
        for i, j in di:
            for _ in range(j):
                res.append(i)
        return res


# @lc code=end
