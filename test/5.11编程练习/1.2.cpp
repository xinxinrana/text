//打印连续十个数

#include<stdio.h>
#define munber 10

int main()
{
    int i=0,j=0;
    printf("输入一个整数,程序会连续输出10个他之后的数");
    scanf("%d",&i);

    for(j=i;i<j+munber;++i)
    {
       printf("%4d",i);
    }

    printf("\n\n");
    return 0;
}
