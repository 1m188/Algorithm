/**
 * @file L1-054 福到了.cpp
 * @date 2022-05-19
 */

/*
“福”字倒着贴，寓意“福到”。不论到底算不算民俗，本题且请你编写程序，把各种汉字倒过来输出。
这里要处理的每个汉字是由一个 N × N 的网格组成的，网格中的元素或者为字符 @ 或者为空格。
而倒过来的汉字所用的字符由裁判指定。

输入格式：
输入在第一行中给出倒过来的汉字所用的字符、以及网格的规模 N （不超过100的正整数），其间以 1 个空格分隔；
随后 N 行，每行给出 N 个字符，或者为 @ 或者为空格。

输出格式：
输出倒置的网格，如样例所示。
但是，如果这个字正过来倒过去是一样的，就先输出bu yong dao le，然后再用输入指定的字符将其输出。

输入样例 1：
$ 9
 @  @@@@@
@@@  @@@ 
 @   @ @ 
@@@  @@@ 
@@@ @@@@@
@@@ @ @ @
@@@ @@@@@
 @  @ @ @
 @  @@@@@

输出样例 1：
$$$$$  $ 
$ $ $  $ 
$$$$$ $$$
$ $ $ $$$
$$$$$ $$$
 $$$  $$$
 $ $   $ 
 $$$  $$$
$$$$$  $ 

输入样例 2：
& 3
@@@
 @ 
@@@

输出样例 2：
bu yong dao le
&&&
 & 
&&&

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <cstdio>
#include <vector>
using namespace std;

int main() {

    char ch = 0;
    int n = 0;
    scanf("%c %d", &ch, &n);
    getchar();

    vector<vector<char>> vec(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c = getchar();
            if (c == '\n')
                c = getchar();
            vec[i][j] = c == ' ' ? c : ch;
        }

    vector<vector<char>> nvec(vec);

    for (int x = 0, y = n - 1; x < y; x++, y--)
        for (int i = 0; i < n; i++)
            swap(nvec[x][i], nvec[y][i]);

    for (int x = 0, y = n - 1; x < y; x++, y--)
        for (int i = 0; i < n; i++)
            swap(nvec[i][x], nvec[i][y]);

    if (vec == nvec)
        printf("bu yong dao le\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", nvec[i][j]);
        printf("\n");
    }

    return 0;
}