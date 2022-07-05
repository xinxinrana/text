// typedef 常规定义函数
#include<stdio.h>

int main(int argc, char const *argv[])
{
    typedef char strings[32];

    strings str_1= {"这就是简单的编程"};

    printf("%s",str_1);
    return 0;
}
