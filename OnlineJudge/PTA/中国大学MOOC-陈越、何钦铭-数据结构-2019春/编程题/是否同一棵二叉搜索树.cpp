/*
04-树4 是否同一棵二叉搜索树 （25 分)
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:

输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:

对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:

Yes
No
No
鸣谢青岛大学周强老师补充测试数据！
*/

#include "iostream"
#include "vector"

bool judge(const std::vector<int> &vec, const std::vector<int> &v)
{
    if (vec.empty() && v.empty())
    {
        return true;
    }
    else if (vec.size() != v.size() || vec[0] != v[0])
    {
        return false;
    }
    else
    {
        std::vector<int> vecBigger, vecSmaller, vBigger, vSmaller;
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] > vec[0])
            {
                vecBigger.push_back(vec[i]);
            }
            else
            {
                vecSmaller.push_back(vec[i]);
            }

            if (v[i] > v[0])
            {
                vBigger.push_back(v[i]);
            }
            else
            {
                vSmaller.push_back(v[i]);
            }
        }

        return judge(vecBigger, vBigger) && judge(vecSmaller, vSmaller);
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    while (N)
    {
        int L = 0;
        std::cin >> L;

        std::vector<int> vec(N);
        for (int i = 0; i < N; i++)
        {
            std::cin >> vec[i];
        }

        while (L--)
        {
            std::vector<int> v(N);
            for (int i = 0; i < N; i++)
            {
                std::cin >> v[i];
            }
            if (judge(vec, v))
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }

        std::cin >> N;
    }

    return 0;
}