/**
 * @file P1059 [NOIP2006 普及组] 明明的随机数.cpp
 * @date 2022-06-01
 */

/*
# [NOIP2006 普及组] 明明的随机数

## 题目描述

明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了$N$个$1$到$1000$之间的随机整数$(N≤100)$，对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。

## 输入格式

输入有两行，第$1$行为$1$个正整数，表示所生成的随机数的个数$N$

第$2$行有$N$个用空格隔开的正整数，为所产生的随机数。

## 输出格式

输出也是两行，第$1$行为$1$个正整数$M$，表示不相同的随机数的个数。

第$2$行为$M$个用空格隔开的正整数，为从小到大排好序的不相同的随机数。

## 样例 #1

### 样例输入 #1

```
10
20 40 32 67 40 20 89 300 400 15
```

### 样例输出 #1

```
8
15 20 32 40 67 89 300 400
```

## 提示

NOIP 2006 普及组 第一题
*/

/* 排序 去重 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it < vec.end();) {
        auto jt = it + 1;
        while (jt < vec.end() && *jt == *it)
            jt++;
        it = vec.erase(it + 1, jt);
    }

    cout << vec.size() << '\n';
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
        cout << ' ' << vec[i];

    return 0;
}