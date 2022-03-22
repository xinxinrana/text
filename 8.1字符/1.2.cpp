//重定向输出
#include <stdio.h>

int main()
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    return 0;
}

//      ls  列出文件夹下文件目录
//      cat 文件名  查看文件