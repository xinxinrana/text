// typedef  和   函数指针
#include <stdio.h>

int reduce(int n);
int add(int n);
int switch_fun(int (*fun)(int), int n);

int main(int argc, char const *argv[])
{
    int number;
    typedef char STRING[32];
    STRING name = {"xiao xiong"};
    printf("%s\n>>", name);

    int (*add_p)(int n) = add;
    int (*reduce_p)(int n) = reduce;

    puts("输入一个整数：\n");
    while ((scanf("%d", &number)) == 1)
    {
        if (number > 10)
        {
            number = switch_fun(add_p, number);
        }
        else
        {
            number = switch_fun(reduce_p, number);
        }

        printf("\n*** %d ***\n", number);
        puts("继续输入或退出：");
    }

    return 0;
}

int switch_fun(int (*fun)(int), int n)
{
    int temp;
    temp = (*fun)(n);
    return temp;
}

int add(int n)
{
    return n + 1;
}
int reduce(int n)
{
    return n - 1;
}
