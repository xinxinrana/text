//字符串常量和数组字符串的区别
#include<stdio.h>
#define MSG "Hello World!"

int main (void)
{
    char ar[] = MSG;        //将字符串再赋值给ar 字符串数组
    const char *pt = MSG;

    printf("MSG的存储位置:         %p\n",MSG);
    printf("pt的存储位置:          %p\n",pt);
    printf("ar的存储位置:          %p\n",ar);   //开辟了新空间
    return 0;
}