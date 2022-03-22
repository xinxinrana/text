//getchar函数测试
//显示1-127的ASCII码
#include<stdio.h>
#define SPACE ' '

int main(void)
{
    unsigned char i = 1;
    for (int i = 0; i < 128; i++)
    {
        printf("%-4d",i);
        putchar(i);
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}
