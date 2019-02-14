/*
标题：魔方状态

二阶魔方就是只有2层的魔方，只由8个小块组成。
如图p1.png所示。

小明很淘气，他只喜欢3种颜色，所有把家里的二阶魔方重新涂了颜色，如下：

前面：橙色
右面：绿色
上面：黄色
左面：绿色
下面：橙色
后面：黄色

请你计算一下，这样的魔方被打乱后，一共有多少种不同的状态。

如果两个状态经过魔方的整体旋转后，各个面的颜色都一致，则认为是同一状态。

请提交表示状态数的整数，不要填写任何多余内容或说明文字。
*/

/*
不知道该怎么做。。。看了网上的几个解答，答案都不一样。。。
我用的是其中一种方法，魔方总共有8块，
然后这8块其中有4块一样，另外2块一样，另外又2块一样，然后就是判断
1 1 1 1 2 2 3 3 的全排列，且这8块的位置不能互换，
换了就是另一种情况了，然后对称的情况就直接/2，这样用dfs判断
一下最后得出的答案和我参考的那篇博客都不一样。。。
其他的比如说有用Burnside引理判断的，看不懂。。。。
还有什么空间搜索+判重什么的。。。。感觉很麻烦。。。
*/

#include "cstdio"

int a[8] = {0};
int c[8] = {1, 1, 1, 1, 2, 2, 3, 3};
bool cIsRepeat[8] = {false};
int num = 0;

void dfs(int d = 0)
{
    if (d == 8)
    {
        num++;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (!cIsRepeat[i])
            {
                cIsRepeat[i] = true;
                a[d] = c[i];
                dfs(d + 1);
                a[d] = 0;
                cIsRepeat[i] = false;
            }
        }
    }
}

int main()
{
    dfs();
    num /= 2;
    printf("%d\n", num);
    return 0;
}