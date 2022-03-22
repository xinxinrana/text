//用户输入与输出        用户指定输入量，再指定输出某一位
#include <stdio.h>
#include <stdlib.h>
#include "s_gets.h"
// #define size_1 32

void put_char(char x, int n);
int main(int argc, char const *argv[])
{
    int size_1 = 64;
    int size_2;

    puts("输入你要输入的单词数：\n"); //字符串数量确定
    scanf("%d", &size_2);
    // while (getchar() != '\n')       //清理缓冲区： scanf 使用后缓存区会留下一个 \n
    //         continue;                //已经在s_gets 函数中实现

    char(*words)[size_1]; //字符串输入
    words = (char(*)[size_1])malloc(size_2 * size_1 * sizeof(char));

    printf("输入 %d 个单词，每次输入后回车再输入下一个！\n", size_2);
    for (int i = 0; i < size_2; i++)
    {
        s_gets(words[i], size_1 - 1);
        printf("great!目前已经输入 %d个\n", i + 1);
    }

    put_char('#', 20); //输出刚刚接受的字符串
    for (int i = 0; i < size_2; i++)
    {
        printf("%3d: %s\n", i + 1, words[i]);
    }
    put_char('#', 20);

    return 0;
}

//打印任意指定长度字符  自带回车
void put_char(char x, int n)
{
    putchar('\n');
    for (int i = 0; i < n; i++)
    {
        putchar(x);
    }
    putchar('\n');
    putchar('\n');
}