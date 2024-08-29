/*

二项式的系数规律，我国数学家很早就发现了。

如【图1.png】，我国南宋数学家杨辉1261年所著的《详解九章算法》一书里就出现了。

其排列规律：
1
1    1
1    2    1
1    3    3    1
1    4    6    4    1
1    5    10   10   5    1
1    6    15   20   15   6    1
1    7    21   35   35   21   7    1

如下的程序，用来建立N行的杨辉三角形。请填写划线部分缺少的代码。

注意：只填写划线部分的代码，不要填写任何多余的内容。


#define N 8
int main()
{
        int a[N][N];
        int i,j;

        for(i=0; i<N; i++){
                a[i][0] = 1;
                a[i][i] = 1;
        }

        for(i=1; i<N; i++){
                for(j=1; j<i; j++) ___________________________;
        }

        for(i=0; i<N; i++){
                for(j=0; j<=i; j++)	printf("%-5d", a[i][j]);
                printf("\n");
        }

        return 0;
}


*/

#include <cstdio>
using namespace std;

#define N 8
int main() {
    int a[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (i = 1; i < N; i++) {
        for (j = 1; j < i; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; // 待填空区域
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++)
            printf("%-5d", a[i][j]);
        printf("\n");
    }

    return 0;
}