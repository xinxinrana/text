//流
//重定向输入
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

//      编译链接：g++ -o Main.out Main.cpp
//                              ^^^源文件

//      ./Main.out<text.txt
//      打开Main.out可执行文件  重定向text.txt文件流