#
# @lc app=leetcode.cn id=2913 lang=python3
#
# [2913] 子数组不同元素数目的平方和 I
#
# https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/description/
#
# algorithms
# Easy (80.20%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    3.2K
# Total Submissions: 4K
# Testcase Example:  '[1,2,1]'
#
# 给你一个下标从 0 开始的整数数组 nums 。
#
# 定义 nums 一个子数组的 不同计数 值如下：
#
#
# 令 nums[i..j] 表示 nums 中所有下标在 i 到 j 范围内的元素构成的子数组（满足 0 <= i <= j < nums.length
# ），那么我们称子数组 nums[i..j] 中不同值的数目为 nums[i..j] 的不同计数。
#
#
# 请你返回 nums 中所有子数组的 不同计数 的 平方 和。
#
# 由于答案可能会很大，请你将它对 10^9 + 7 取余 后返回。
#
# 子数组指的是一个数组里面一段连续 非空 的元素序列。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,1]
# 输出：15
# 解释：六个子数组分别为：
# [1]: 1 个互不相同的元素。
# [2]: 1 个互不相同的元素。
# [1]: 1 个互不相同的元素。
# [1,2]: 2 个互不相同的元素。
# [2,1]: 2 个互不相同的元素。
# [1,2,1]: 2 个互不相同的元素。
# 所有不同计数的平方和为 1^2 + 1^2 + 1^2 + 2^2 + 2^2 + 2^2 = 15 。
#
#
# 示例 2：
#
#
# 输入：nums = [2,2]
# 输出：3
# 解释：三个子数组分别为：
# [2]: 1 个互不相同的元素。
# [2]: 1 个互不相同的元素。
# [2,2]: 1 个互不相同的元素。
# 所有不同计数的平方和为 1^2 + 1^2 + 1^2 = 3 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:

    def sumCounts(self, nums: List[int]) -> int:

        MOD = 1e9 + 7

        res = 0
        for i in range(len(nums)):
            se = set()
            for j in range(i, len(nums)):
                se.add(nums[j])
                res += len(se)**2
        return int(res % MOD)


# @lc code=end
