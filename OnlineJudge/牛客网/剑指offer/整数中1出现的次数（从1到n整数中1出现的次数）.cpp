/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

//这题想了好久都没有想出来，没有想法，之后去看了别人的解答，勉强理解了一点，但是对于如何归纳出这种方法，还是没有办法

/*
别人的方法：


主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析

根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i

当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，
即共有(a%10+1)*100个点的百位为1

当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，
当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1

当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）


这里只是拿百位来举例子，实际操作需要使用i而不是100
*/

class Solution
{
  public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int num = 0;
        for (int i = 1; i <= n; i *= 10)
        {
            int a = n / i, b = n % i;
            int bitNum = a % 10;
            if (bitNum == 0)
            {
                num += a / 10 * i;
            }
            else if (bitNum == 1)
            {
                num += a / 10 * i + b + 1;
            }
            else
            {
                num += (a / 10 + 1) * i;
            }
        }
        return num;
    }
};