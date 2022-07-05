//天数转周数
#include<stdio.h>

int main()
{
    int day1=0;
    int wek,day2;
    printf("天数转环为 X周又X天\n");
    printf("输入一个整数\n");
    scanf("%d",&day1);

    wek = day1/7;
    day2 = day1%7;
    printf("%d天是%d周又%d天\n\n",day1,wek,day2);

    return 0;
}
