#
# @lc app=leetcode.cn id=2869 lang=python3
#
# [2869] 收集元素的最少操作次数
#
# https://leetcode.cn/problems/minimum-operations-to-collect-elements/description/
#
# algorithms
# Easy (71.42%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3.7K
# Total Submissions: 5.2K
# Testcase Example:  '[3,1,5,4,2]\n2'
#
# 给你一个正整数数组 nums 和一个整数 k 。
#
# 一次操作中，你可以将数组的最后一个元素删除，将该元素添加到一个集合中。
#
# 请你返回收集元素 1, 2, ..., k 需要的 最少操作次数 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [3,1,5,4,2], k = 2
# 输出：4
# 解释：4 次操作后，集合中的元素依次添加了 2 ，4 ，5 和 1 。此时集合中包含元素 1 和 2 ，所以答案为 4 。
#
#
# 示例 2：
#
#
# 输入：nums = [3,1,5,4,2], k = 5
# 输出：5
# 解释：5 次操作后，集合中的元素依次添加了 2 ，4 ，5 ，1 和 3 。此时集合中包含元素 1 到 5 ，所以答案为 5 。
#
#
# 示例 3：
#
#
# 输入：nums = [3,2,5,3,1], k = 3
# 输出：4
# 解释：4 次操作后，集合中的元素依次添加了 1 ，3 ，5 和 2 。此时集合中包含元素 1 到 3  ，所以答案为 4 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 50
# 1 <= nums[i] <= nums.length
# 1 <= k <= nums.length
# 输入保证你可以收集到元素 1, 2, ..., k 。
#
#
#

from typing import List


# @lc code=start
class Solution:

    def minOperations(self, nums: List[int], k: int) -> int:

        res = 0

        f = 0
        ff = (1 << k) - 1
        while f != ff:
            res += 1
            x = nums.pop()
            if x > k: continue
            xx = 1 << (x - 1)
            if xx & f > 0: continue
            f += xx

        return res


# @lc code=end
