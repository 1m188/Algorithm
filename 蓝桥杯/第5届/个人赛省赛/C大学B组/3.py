'''

如果x的x次幂结果为10（参见【图1.png】），你能计算出x的近似值吗？

显然，这个值是介于2和3之间的一个数字。

请把x的值计算到小数后6位（四舍五入），并填写这个小数值。

注意：只填写一个小数，不要写任何多余的符号或说明。

  x
x   =  10



'''

FLOAT = 10**-6

left, right = 2, 3
while True:
    x = (left + right) / 2
    y = x**x - 10
    if abs(y) < FLOAT: break
    elif y > 0: right = x
    else: left = x
print(round(x, 6))
