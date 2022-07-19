/**
 * @file P1208 [USACO1.3]混合牛奶 Mixing Milk.cpp
 * @date 2022-07-19
 */

/*
# [USACO1.3]混合牛奶 Mixing Milk

## 题目描述

由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。帮助 Marry 乳业找到最优的牛奶采购方案。

Marry 乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格是不同的。此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。每天 Marry 乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。

给出 Marry 乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。计算采购足够数量的牛奶所需的最小花费。

注：每天所有奶农的总产量大于 Marry 乳业的需求量。

## 输入格式

第一行二个整数 $n,m$，表示需要牛奶的总量，和提供牛奶的农民个数。

接下来 $m$ 行，每行两个整数 $p_i,a_i$，表示第 $i$ 个农民牛奶的单价，和农民 $i$ 一天最多能卖出的牛奶量。

## 输出格式

单独的一行包含单独的一个整数，表示 Marry 的牛奶制造公司拿到所需的牛奶所要的最小费用。

## 样例 #1

### 样例输入 #1

```
100 5
5 20
9 40
3 10
8 80
6 30
```

### 样例输出 #1

```
630
```

## 提示

【数据范围】  
对于 $100\%$ 的数据：  
$0 \le n,a_i \le 2 \times 10^6$，$0\le m \le 5000$，$0 \le p_i \le 1000$

题目翻译来自 NOCOW。

USACO Training Section 1.3
*/

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int p = 0, a = 0;
};

vector<Node> vec;
int n = 0, m = 0;

int main() {

    scanf("%d %d", &n, &m);
    vec.resize(m);

    for (int i = 0; i < m; i++)
        scanf("%d %d", &vec[i].p, &vec[i].a);

    sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) {
        return e1.p < e2.p;
    });

    int res = 0;

    for (const Node &e : vec) {
        if (e.a < n) {
            n -= e.a;
            res += e.a * e.p;
        } else {
            res += n * e.p;
            break;
        }
    }

    printf("%d", res);

    return 0;
}