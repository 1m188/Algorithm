
// 今有7对数字：两个1，两个2，两个3，...两个7，把它们排成一行。
// 要求，两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。
// 如下就是一个符合要求的排列：

// 17126425374635

// 当然，如果把它倒过来，也是符合要求的。

// 请你找出另一种符合要求的排列法，并且这个排列法是以74开头的。

// 注意：只填写这个14位的整数，不能填写任何多余的内容，比如说明注释等。

#include <iostream>
#include <vector>

using namespace std;

vector<int> num(14, 0);
vector<bool> flags(8, false);
bool f = false;

void dfs(int idx = 0)
{
    if (idx == 5)
    {
        f = true;
        for (const int &n : num) // 74151643752362
            cout << n;
        cout << '\n';
        return;
    }

    for (int i = 0; i < 14; i++)
    {
        if (!num[i])
        {
            for (int j = 1; j <= 7; j++)
            {
                if (!flags[j] && i + j + 1 < 14 && !num[i + j + 1])
                {
                    flags[j] = true;
                    num[i] = num[i + j + 1] = j;
                    dfs(idx + 1);
                    if (f)
                        return;
                    num[i] = num[i + j + 1] = 0;
                    flags[j] = false;
                }
            }
        }
    }
}

int main()
{
    num[0] = num[8] = 7, num[1] = num[6] = 4; // 74xxxx4x7xxxxx

    flags[7] = flags[4] = true;

    dfs();

    return 0;
}