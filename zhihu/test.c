#include <stdio.h>
int main()
{
    int A, B, C, D, n; //分为ABCD四个数，n仅为计算该程序最终循环次数，非必要
    int a, b, c, d;
    for (A = 1; A <= 7; A++) //按照题设，每个数最小为1最大为7
        for (B = 1; B <= 7; B++)
            for (C = 1; C <= 7; C++)
                for (D = 1; D <= 7; D++)
                {
                    a = (A >= 5); //当其中一个数大于等于5的情况
                    b = (B >= 5);
                    c = (C >= 5);
                    d = (D >= 5);
                    n++;                                               //计数用
                    if ((a + b + c + d == 1) && (A + B + C + D == 10)) //四个数当中有大于等于5的情况只出现一次且四个数相加等于10
                        printf("A=%d,B=%d,C=%d,D=%d,运行%d次\n", A, B, C, D, n);
                }
    return 0;
}