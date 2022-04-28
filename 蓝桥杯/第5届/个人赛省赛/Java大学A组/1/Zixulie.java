
// 一个串的子串是指该串的一个连续的局部。如果不要求连续，则可称为它的子序列。
// 比如对串： "abcdefg" 而言，"ab","abd","bdef" 等都是它的子序列。
// 特别地，一个串本身，以及空串也是它的子序列。

// 对两个串而言，可以有许多的共同的子序列，我们关心的是：它们所共同拥有的长度最大的子序列是多长。以下代码实现了这个问题的求解。请填写划线部分缺失的代码。

// 注意：只填写缺少的代码，不要写任何多余的内容，比如注释或说明文字。

// public class Zixulie
// {
// 	public static int f(String x, String y)
// 	{
// 		if(x.length()==0) return 0;
// 		if(y.length()==0) return 0;

// 		String x1 = x.substring(1);
// 		String y1 = y.substring(1);	

// 		if(x.charAt(0)==y.charAt(0)) return f(x1,y1)+1;

// 		return __________________________;
// 	}

// 	public static void main(String[] args)
// 	{
// 		System.out.println(f("ac","abcd")); //2
// 		System.out.println(f("acebbcde1133","xya33bc11de")); //5
// 	}
// }

import java.lang.System;
import java.lang.Math;

public class Zixulie {
    public static int f(String x, String y) {
        if (x.length() == 0)
            return 0;
        if (y.length() == 0)
            return 0;

        String x1 = x.substring(1);
        String y1 = y.substring(1);

        if (x.charAt(0) == y.charAt(0))
            return f(x1, y1) + 1;

        return Math.max(f(x, y1), f(x1, y)); // 返回二者中的最大值 二者有很多重复内容
    }

    public static void main(String[] args) {
        System.out.println(f("ac", "abcd")); // 2
        System.out.println(f("acebbcde1133", "xya33bc11de")); // 5
    }
}