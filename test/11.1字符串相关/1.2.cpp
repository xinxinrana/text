//值符串的输入
// gets（）      //大都不用，容易修改未定义内存的值
// fgets（）     //常用，但是需要处理未读取缓冲池内的值
// gets_s()      //gets 进阶版 输入过长会需要处理函数 但是输入过长数据会丢失
#include <stdio.h>
#define STLEN 10

void p_1 (int num);
int main(void)
{
    char words[STLEN];

    while (fgets(&words[0], STLEN, stdin) != NULL && words[0] != '\n')
    {
        int i = 0;
        while (words[i]!='\n'&&words[i]!='\0')
            i++;
        if (words[i]=='\n')
            words[i]='\0';
        else
            while(getchar()!='\n')
            continue;
            
        putchar('\n');p_1(30);putchar('\n');
        puts(words);
        putchar('\n');p_1(30);putchar('\n');
        fputs(&words[0], stdout);
        putchar('\n');p_1(30);putchar('\n');
        
        
    }
    puts("done!");



    return 0;
}

void p_1 (int num)
{
    for(int i =0;i<num;i++)
    {
        putchar('#');
    }
}