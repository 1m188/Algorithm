'''
问题描述
试题编号：	202012-2
试题名称：	期末预测之最佳阈值
时间限制：	1.0s
内存限制：	512.0MB
问题描述：	
题目背景
考虑到安全指数是一个较大范围内的整数、小菜很可能搞不清楚自己是否真的安全，顿顿决定设置一个阈值 
，以便将安全指数 
 转化为一个具体的预测结果——“会挂科”或“不会挂科”。

因为安全指数越高表明小菜同学挂科的可能性越低，所以当 
 时，顿顿会预测小菜这学期很安全、不会挂科；反之若 
，顿顿就会劝诫小菜：“你期末要挂科了，勿谓言之不预也。”

那么这个阈值该如何设定呢？顿顿准备从过往中寻找答案。

题目描述
具体来说，顿顿评估了 
 位同学上学期的安全指数，其中第 
（
）位同学的安全指数为 
，是一个 
 范围内的整数；同时，该同学上学期的挂科情况记作 
，其中 
 表示挂科、
 表示未挂科。

相应地，顿顿用 
 表示根据阈值 
 将安全指数 
 转化为的具体预测结果。
如果 
 与 
 相同，则说明阈值为 
 时顿顿对第 
 位同学是否挂科预测正确；不同则说明预测错误。

 

最后，顿顿设计了如下公式来计算最佳阈值 
：

 
 

该公式亦可等价地表述为如下规则：

最佳阈值仅在 
 中选取，即与某位同学的安全指数相同；

按照该阈值对这 
 位同学上学期的挂科情况进行预测，预测正确的次数最多（即准确率最高）；

多个阈值均可以达到最高准确率时，选取其中最大的。

输入格式
从标准输入读入数据。

输入的第一行包含一个正整数 
。

接下来输入 
 行，其中第 
（
）行包括用空格分隔的两个整数 
 和 
，含义如上文所述。

输出格式
输出到标准输出。

输出一个整数，表示最佳阈值 
。

样例1输入
6
0 0
1 0
1 1
3 1
5 1
7 1
Data
样例1输出
3
Data
样例1解释
按照规则一，最佳阈值的选取范围为 
。

 时，预测正确次数为 
；

 时，预测正确次数为 
；

 时，预测正确次数为 
；

 时，预测正确次数为 
；

 时，预测正确次数为 
。

阈值选取为 
 或 
 时，预测准确率最高；
所以按照规则二，最佳阈值的选取范围缩小为 
。

依规则三，
。

样例2输入
8
5 1
5 0
5 0
2 1
3 0
4 0
100000000 1
1 0
Data
样例2输出
100000000
Data
子任务
 的测试数据保证 
；

全部的测试数据保证 
。
'''

# 这一题主要是看theta前后的1和0的数目，将成绩从小到大排列，记录下1和0，
# 只需要遍历一次即可，时间复杂度O(n)

m = int(input())
vec = []
for _ in range(m):
    vec.append(tuple(map(int, input().split())))
vec.sort(key=lambda x: x[0])
zero, one = 0, 0
for _, i in vec:
    if i == 1: one += 1

theta_x, cnt_x = 0, -1
for i, (g, r) in enumerate(vec):
    if i > 0 and vec[i][0] == vec[i - 1][0]:
        if r == 0: zero += 1
        else: one -= 1
        continue
    if one + zero > cnt_x or (one + zero == cnt_x and g > theta_x):
        theta_x = g
        cnt_x = one + zero
    if r == 0: zero += 1
    else: one -= 1

print(theta_x)
