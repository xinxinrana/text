//作业
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char month[12][20] = {"一月January",
                          "二月February",
                          "三月March",
                          "四月April",
                          "五月May",
                          "六月June",
                          "七月July",
                          "八月 August",
                          "九月 September",
                          "十月 October",
                          "十一月November",
                          "十二月December"};

    int month_in;
    printf("输入一个月份数值\n");

    while ((scanf("%d", &month_in)) == 1)
    {
        if ((month_in<1)||(month_in>12))
        {
            exit(0);
        }
        
        for (int i = 1; i < 13; i++)
        {
            if (i == month_in)
            {
                printf("%s\n", month[i - 1]);
            }
        }

        printf("输入一个月份数值\n");
    }

    return 0;
}
