//for循环中 ++i  与  i++  的区别测试
//结论：无论 ++i  与  i++  都是先自增 再判断。
#include<stdio.h>

int main (void)
{
    for(int i =0;i<=10;i++)
    {
        printf("%3d",i);
    }

    putchar('\n');putchar('\n');putchar('\n');

    for(int i =0;i<=10;++i)
    {
        printf("%3d",i);
    }
    return 0;
}