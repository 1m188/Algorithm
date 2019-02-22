/*
7-4 BCD解密 （10 分）
BCD数是用一个字节来表达两位十进制的数，每四个比特表示一位。所以如果一个BCD数的十六进制是0x12，它表达的就是十进制的12。但是小明没学过BCD，把所有的BCD数都当作二进制数转换成十进制输出了。于是BCD的0x12被输出成了十进制的18了！

现在，你的程序要读入这个错误的十进制数，然后输出正确的十进制数。提示：你可以把18转换回0x12，然后再转换回12。

输入格式：

输入在一行中给出一个[0, 153]范围内的正整数，保证能转换回有效的BCD数，也就是说这个整数转换成十六进制时不会出现A-F的数字。

输出格式：

输出对应的十进制数。

输入样例：

18
输出样例：

12
*/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

int main()
{
    int num = 0;
    std::cin >> num;

    if (num == 0)
    {
        std::cout << 0;
    }
    else
    {
        std::vector<std::string> vec;
        while (num)
        {
            vec.push_back(std::to_string(num % 16));
            num /= 16;
        }
        std::reverse(vec.begin(), vec.end());

        std::for_each(vec.begin(), vec.end(), [](const std::string &s) { std::cout << s; });
    }

    return 0;
}