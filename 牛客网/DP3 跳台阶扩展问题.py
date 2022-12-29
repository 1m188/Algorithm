'''
描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。

数据范围：1 \le n \le 201≤n≤20
进阶：空间复杂度 O(1)O(1) ， 时间复杂度 O(1)O(1)
输入描述：
本题输入仅一行，即一个整数 n 
输出描述：
输出跳上 n 级台阶的跳法
示例1
输入：
3
复制
输出：
4
复制
示例2
输入：
1
复制
输出：
1
'''
'''
跳台阶的扩展问题
dp[i] = dp[1] + dp[2] + dp[3] + ... + dp[n - 1] + 1
最后一个1是一次性跳上i阶
'''

n = int(input())
dp = [0 for _ in range(n + 1)]
dp[1] = 1
for i in range(2, n + 1):
    for j in range(1, i):
        dp[i] += dp[j]
    dp[i] += 1
print(dp[n])