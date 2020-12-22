/*
    File:   435942060.c - C语言编程输出0到99个位不能为七的整数的语句是什么？
    Copyright:  © 2020-2025 brave_brother. All rights reserved.
 */
extern int printf(const char *format, ...);

int main()
{
    for (int n = 0; n < 100; n++)
        if ((n % 10) != 7)
            printf("%d ", n);

    return 0;
}