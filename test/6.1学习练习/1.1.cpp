//求极限
#include <stdio.h>

int main()
{
    int i, j;
    double limit = 0;

    printf("次数：      次数和\n");
    for (i = 1, j = 1; j < 30; i *= 2, j++)
    {
        //  1 + 1/2 + 1/4  循环29次
        limit += (1 / (double)i);
        printf("%d次后的和是：%10.9lf\n", j, limit);
    }

    return 0;
}
