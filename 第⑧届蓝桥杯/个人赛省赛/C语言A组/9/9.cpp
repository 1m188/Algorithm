/*
标题： 分巧克力

    儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
    小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。

    为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：

    1. 形状是正方形，边长是整数  
    2. 大小相同  

例如一块6x5的巧克力可以切出6块2x2的巧克力或者2块3x3的巧克力。

当然小朋友们都希望得到的巧克力尽可能大，你能帮小Hi计算出最大的边长是多少么？

输入
第一行包含两个整数N和K。(1 <= N, K <= 100000)  
以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000) 
输入保证每位小朋友至少能获得一块1x1的巧克力。   

输出
输出切出的正方形巧克力最大可能的边长。

样例输入：
2 10  
6 5  
5 6  

样例输出：
2

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

//又是看了别人的思路才写出来......

/*
思路：假如边长为code，一块可分为 （长除以code）乘上（宽除以code） 块
所以初始让code为一，每次算出可分出的总块数，然后与k（人数）比较，若大于人数，code++,否则code-1就是最大边
*/

#include "iostream"
#include "vector"

int main()
{
    int N = 0, K = 0;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> vec[i].first >> vec[i].second;
    }

    int code = 1;
    while (true)
    {
        int sum = 0;
        for (auto cit = vec.cbegin(); cit < vec.cend(); cit++)
        {
            sum += (cit->first / code) * (cit->second / code);
        }
        if (sum > K)
        {
            code++;
        }
        else
        {
            code--;
            break;
        }
    }

    std::cout << code;

    return 0;
}
