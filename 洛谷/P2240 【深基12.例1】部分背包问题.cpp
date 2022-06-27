/**
 * @file P2240 【深基12.例1】部分背包问题.cpp
 * @date 2022-06-27
 */

/*
# 【深基12.例1】部分背包问题

## 题目描述

阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有 $N(N \le 100)$ 堆金币，第 $i$ 堆金币的总重量和总价值分别是 $m_i,v_i(1\le m_i,v_i \le 100)$。阿里巴巴有一个承重量为 $T(T \le 1000)$ 的背包，但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？

## 输入格式

第一行两个整数 $N,T$。

接下来 $N$ 行，每行两个整数 $m_i,v_i$。

## 输出格式

一个实数表示答案，输出两位小数

## 样例 #1

### 样例输入 #1

```
4 50
10 60
20 100
30 120
15 45
```

### 样例输出 #1

```
240.00
```
*/

/* 优先拿单位价值高的 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int m = 0, v = 0;
    double per = 0;

    bool operator<(const Node &e) {
        return per > e.per;
    }
};

vector<Node> vec;
int n = 0, t = 0;

int main() {

    scanf("%d %d", &n, &t);
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &vec[i].m, &vec[i].v);
        vec[i].per = double(vec[i].v) / vec[i].m;
    }

    sort(vec.begin(), vec.end());

    double ans = 0;

    for (const auto &e : vec) {
        if (e.m < t) {
            ans += e.v;
            t -= e.m;
        } else {
            ans += t * e.per;
            break;
        }
    }

    printf("%.2lf", ans);

    return 0;
}