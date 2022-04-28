
// 一个串的子串是指该串的一个连续的局部。如果不要求连续，则可称为它的子序列。
// 比如对串： "abcdefg" 而言，"ab","abd","bdef" 等都是它的子序列。
// 特别地，一个串本身，以及空串也是它的子序列。

// 对两个串而言，可以有许多的共同的子序列，我们关心的是：它们所共同拥有的长度最大的子序列是多长。以下代码实现了这个问题的求解。请填写划线部分缺失的代码。

// 注意：只填写划线部分缺少的内容，不要填写任何多余的符号或注释、说明等。例如，不要填写已经给出的小括号。

// inline max(int a, int b)
// {
// 	return a>b?a:b;
// }

// int f(char* x, char* y)
// {
// 	if(strlen(x)==0) return 0;
// 	if(strlen(y)==0) return 0;

// 	if(*x == *y) return f(x+1, y+1) + 1;

// 	return max( ______________________ );
// }

// int main()
// {
// 	printf("%d\n", f("ac","abcd")); //2
// 	printf("%d\n", f("acebbcde1133","xya33bc11de")); //5
// 	return 0;
// }

#include "cstdio"
#include "cstring"

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int f(char *x, char *y)
{
    if (strlen(x) == 0)
        return 0;
    if (strlen(y) == 0)
        return 0;

    if (*x == *y)
        return f(x + 1, y + 1) + 1;

    return max(f(x + 1, y), f(x, y + 1));
}

int main()
{
    printf("%d\n", f("ac", "abcd"));                  //2
    printf("%d\n", f("acebbcde1133", "xya33bc11de")); //5
    return 0;
}