// s_gets() 函数 即fget（）的嵌套
#include <stdio.h>

char *s_gets(char *words, int n);
int main(void)
{
    int size = 10;
    int scanf_bool;
    char words[size];
    char words_2[size];

    puts("输入数据(现在是s_gets()函数)");
    if (!(*s_gets(words, size)))
    {
        puts("ERR!");
    }

    puts("输入数据(现在是scanf()函数)");
    scanf_bool = scanf("%s", words_2);

    puts("输出数据(现在是s_gets()函数)");
    puts(words);

    puts("输出数据(现在是scanf()函数)");
    puts(words_2);

    puts("scanf()函数返回值");
    printf("%d",scanf_bool);

    return 0;
}

char *s_gets(char *words, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(words, n + 1, stdin);
    if (ret_val != NULL)
    {
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}