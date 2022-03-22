//平均数
#include <stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    double average;
    int count = 0;
    int sum = 0;
    int temp_in[32];
    memset(temp_in,0,sizeof(temp_in));

    while ((scanf("%d", &temp_in[count])) == 1)
    {
        sum=sum +temp_in[count];
        count++;
    }
    count--;

    for (int i = 0; i < (count + 1); i++)
    {
        if (i == count)
        {
            printf(" %d =", temp_in[i]);
        }
        else
        {
            printf(" %d +", temp_in[i]);
        }
    }
    printf(" %d \n", sum);
    printf(" 数据个数： %d \n", count + 1);

    average = ((double)sum) / (count + 1);
    printf(" 平均数%lf\n",average);
    printf(" 储存数组占用了%zd * %zd 空间",sizeof(temp_in)/sizeof(int),sizeof(int));

    return 0;
}
