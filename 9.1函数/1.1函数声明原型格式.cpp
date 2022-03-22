//函数声明原型格式
#include<stdio.h>

void show_char(char,int);

int main(void)
{
    char ch = 'c';
    int i=2;
    show_char(ch,i);
    return 0;
}


void show_char(char ch,int num)
{
    for(int i=0;i<num;i++)
    {
        putchar(ch);
    }
}