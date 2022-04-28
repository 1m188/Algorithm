
//   勾股定理，西方称为毕达哥拉斯定理，它所对应的三角形现在称为：直角三角形。

//   已知直角三角形的斜边是某个整数，并且要求另外两条边也必须是整数。

//   求满足这个条件的不同直角三角形的个数。

// 【数据格式】
// 输入一个整数 n (0<n<10000000) 表示直角三角形斜边的长度。
// 要求输出一个整数，表示满足条件的直角三角形个数。

// 例如，输入：
// 5
// 程序应该输出：
// 1

// 再例如，输入：
// 100
// 程序应该输出：
// 2

// 再例如，输入：
// 3
// 程序应该输出：
// 0

// 资源约定：
// 峰值内存消耗 < 256M
// CPU消耗  < 1000ms

// 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

// 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

// 注意: main函数需要返回0
// 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
// 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

// 提交时，注意选择所期望的编译器类型。

#include <cmath>
#include <iostream>

using namespace std;

int getNum(int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        long long k = n * n - i * i;
        ans += (long long)(sqrt(k)) == sqrt(k);
        if (sqrt(k) == i)
            ans += 1; // 这里又+1是为了抹平上面两条边互换时候的增值，使得最后除以2可以得到正确的结果
    }
    return ans / 2;
}

int main()
{
    int n = 0;
    cin >> n;

    cout << getNum(n);

    return 0;
}