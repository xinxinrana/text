// 字符串转整数函数
#include <stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int count  = 127;
    for (int i = 33; i < count; i++)
    {
        printf("%4d:%c  ",i,(char)i);
        putchar('\n');
        
    }
    
    char str[] = {"-3"};

    int str_num = atoi(str);        //atoi 将字符数值 转位int数值

    printf("*%d*",str_num);
    return 0;
}
