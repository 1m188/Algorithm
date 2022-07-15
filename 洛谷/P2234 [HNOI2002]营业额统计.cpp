/**
 * @file P2234 [HNOI2002]营业额统计.cpp
 * @date 2022-07-15
 */

/*
# [HNOI2002]营业额统计

## 题目描述

Tiger 最近被公司升任为营业部经理，他上任后接受公司交给的第一项任务便是统计并分析公司成立以来的营业情况。

Tiger 拿出了公司的账本，账本上记录了公司成立以来每天的营业额。分析营业情况是一项相当复杂的工作。由于节假日，大减价或者是其他情况的时候，营业额会出现一定的波动，当然一定的波动是能够接受的，但是在某些时候营业额突变得很高或是很低，这就证明公司此时的经营状况出现了问题。经济管理学上定义了一种最小波动值来衡量这种情况：当最小波动值越大时，就说明营业情况越不稳定。

而分析整个公司的从成立到现在营业情况是否稳定，只需要把每一天的最小波动值加起来就可以了。你的任务就是编写一个程序帮助 Tiger 来计算这一个值。

我们定义，一天的最小波动值 = $\min\{|\text{该天以前某一天的营业额}-\text{该天营业额}|\}$。

特别地，第一天的最小波动值为第一天的营业额。

## 输入格式

第一行为正整数 $n$（$n \leq 32767$） ，表示该公司从成立一直到现在的天数，接下来的 $n$ 行每行有一个整数 $a_i$（$|a_i| \leq 10^6$) ，表示第 $i$ 天公司的营业额，可能存在负数。

## 输出格式

输出一个正整数，即每一天最小波动值的和，保证结果小于 $2^{31}$。

## 样例 #1

### 样例输入 #1

```
6
5
1
2
5
4
6
```

### 样例输出 #1

```
12
```

## 提示

结果说明：$5+|1-5|+|2-1|+|5-5|+|4-5|+|6-5|=5+4+1+0+1+1=12$
*/

/* 应该要用平衡树做的，这里用的是排序，按值排序，左右找天数在之前的，求最小的绝对值差 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int day = -1;
    int val = 0;
};

int n = 0;
vector<Node> vec;

int main() {

    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i].val);
        vec[i].day = i;
    }

    sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) {
        return e1.val < e2.val;
    });

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i].day == 0) {
            res += vec[i].val;
            continue;
        }

        int x1 = INT_MAX, x2 = INT_MAX;
        for (int j = i - 1; j >= 0; j--) {
            if (vec[j].day < vec[i].day) {
                x1 = abs(vec[i].val - vec[j].val);
                break;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (vec[j].day < vec[i].day) {
                x2 = abs(vec[i].val - vec[j].val);
                break;
            }
        }

        res += min(x1, x2);
    }

    printf("%d", res);

    return 0;
}