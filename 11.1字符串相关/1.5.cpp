// string.h 中的字符串函数
#include <stdio.h>
#include <string.h>
#define DDD "hello \0world!"

char *s_gets(char *words, int n);
// const 才能接受字符串常量！！！
// const 才能接受字符串常量！！！
const char *p = DDD; // const 才能接受字符串常量！！！
char ch[80];
char ch_in[80];
int _n = 0;
int main(void)
{

    for (int i = 0; i < 80; i++)
    {
        if (p + 1)
            ch[i] = *(p + i);
        else
            break;
    }

    // strlen()  字符串长度
    printf("%s的字符串长度是:%zd\n\n", DDD, strlen(DDD));
    printf("%s的字符串长度是:%zd\n\n", p + (strlen(DDD) + 1), strlen(p + (strlen(DDD) + 1)));

    // strcat()  拼接字符   无限制 可能溢出
    printf("拼接后的:%s\n\n", strcat(ch, p + (strlen(DDD) + 1)));

    // strncat() 拼接字符 溢出控制
    puts("再拼接一个words！ 但限制为5位");
    puts(strncat(ch, p + (strlen(DDD) + 1), 5));

    puts("输入world!");
    s_gets(ch_in,80);
    while(strcmp(ch_in,(p + (strlen(DDD) + 1))))
    {
        puts("输错了！重新输！");
        s_gets(ch_in,80);
    }
    puts(ch_in+6);

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