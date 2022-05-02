#
# @lc app=leetcode.cn id=645 lang=python3
#
# [645] 错误的集合
#
# https://leetcode-cn.com/problems/set-mismatch/description/
#
# algorithms
# Easy (41.88%)
# Likes:    264
# Dislikes: 0
# Total Accepted:    81.1K
# Total Submissions: 193.7K
# Testcase Example:  '[1,2,2,4]'
#
# 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且
# 有一个数字重复 。
#
# 给定一个数组 nums 代表了集合 S 发生错误后的结果。
#
# 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,2,4]
# 输出：[2,3]
#
#
# 示例 2：
#
#
# 输入：nums = [1,1]
# 输出：[1,2]
#
#
#
#
# 提示：
#
#
# 2 <= nums.length <= 10^4
# 1 <= nums[i] <= 10^4
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findErrorNums(self, nums: List[int]) -> List[int]:

        ans = [0, 0]

        flags = [False for _ in range(len(nums))]

        for i in nums:  # 找到重复的数字，并对所有已有的数字置标志位
            if not flags[i - 1]: flags[i - 1] = True
            else: ans[0] = i

        for i in range(len(flags)):  # 找到没有置标志位的数字，就是缺失的数字
            if not flags[i]: ans[1] = i + 1

        return ans


# @lc code=end
