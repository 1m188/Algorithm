/*
密码脱落

X星球的考古学家发现了一批古代留下来的密码。
这些密码是由A、B、C、D 四种植物的种子串成的序列。
仔细分析发现，这些密码串当初应该是前后对称的（也就是我们说的镜像串）。
由于年代久远，其中许多种子脱落了，因而可能会失去镜像的特征。

你的任务是：
给定一个现在看到的密码串，计算一下从当初的状态，它要至少脱落多少个种子，才可能会变成现在的样子。

输入一行，表示现在看到的密码串（长度不大于1000）
要求输出一个正整数，表示至少脱落了多少个种子。

例如，输入：
ABCBA
则程序应该输出：
0

再例如，输入：
ABDCDCBABC
则程序应该输出：
3

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

#include "iostream"
#include "string"
#include "algorithm"

int Password(std::string s) //从左右两边分别判断有多少字母不同，取最小的那个作为至少要脱落的密码数
{
    int num = 0;
    int min = 0;
    int i = 0, j = s.size() - 1;
    for (int index = 0; index < 2; index++)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                i++;
                num++;
            }
            else
            {
                i++;
                j--;
            }
        }
        if (index == 0)
        {
            min = num;
            num = 0;
            i = 0, j = s.size() - 1;
            std::reverse(s.begin(), s.end());
        }
    }
    min = min < num ? min : num;
    return min;
}

int main()
{
    std::string s = "";
    std::cin >> s;
    std::cout << Password(s) << std::endl;

    return 0;
}