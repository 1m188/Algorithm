/*
打印方格

小明想在控制台上输出 m x n 个方格。
比如 10x4的，输出的样子是：
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

（如果显示有问题，可以参见【图1.jpg】）

以下是小明写的程序，请你分析其流程，填写划线部分缺少的代码。


#include <stdio.h>

//打印m列，n行的方格 
void f(int m, int n)
{
	int row;
	int col;
	
	for(row=0; row<n; row++){
		for(col=0; col<m; col++) printf("+---");
		printf("+\n");
		for(col=0; col<m; col++) printf("|   ");
		printf("|\n");		
	}
	
	printf("+");
	_____________________________;   //填空
	printf("\n");
}

int main()
{
	f(10,4);
	return 0;
}

注意：仅仅填写划线部分缺少的内容，不要添加任何已有内容或说明性文字。
*/

#include <stdio.h>

//打印m列，n行的方格
void f(int m, int n)
{
    int row;
    int col;

    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
            printf("+---");
        printf("+\n");
        for (col = 0; col < m; col++)
            printf("|   ");
        printf("|\n");
    }

    printf("+");

    for (col = 0; col < m; col++)
        printf("---+"); //填空

    printf("\n");
}

int main()
{
    f(10, 4);
    return 0;
}