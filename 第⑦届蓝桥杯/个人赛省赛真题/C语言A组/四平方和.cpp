/*
四平方和

四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。

比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）

对于一个给定的正整数，可能存在多种平方和的表示法。
要求你对4个数排序：
0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法


程序输入为一个正整数N (N<5000000)
要求输出4个非负整数，按从小到大排序，中间用空格分开

例如，输入：
5
则程序应该输出：
0 0 1 2

再例如，输入：
12
则程序应该输出：
0 2 2 2

再例如，输入：
773535
则程序应该输出：
1 1 267 838

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

#include "cmath"
#include "iostream"

void FourNumAdd(int N)
{
    for (int a = 0; a <= sqrt(N); a++)
    {
        for (int b = a; b <= sqrt(N); b++)
        {
            for (int c = b; c <= sqrt(N); c++)
            {
                for (int d = c; d <= sqrt(N); d++)
                {
                    if (static_cast<int>(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2)) == N)
                    {
                        std::cout << a << ' ' << b << ' ' << c << ' ' << d;
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    FourNumAdd(N);

    return 0;
}