// return与函数调用

#include <stdio.h>
#include <string.h>

#define sentence_1 "Hello world!"
#define sentence_2 "Loading"
#define sentence_3 "good bye"
#define len 40

void show_char(char ch, int num);

int main(void)
{
    show_char('*', len);
    putchar('\n');
    putchar('\n');

    show_char(' ', (len - strlen(sentence_1)) / 2);
    printf("%s",sentence_1);
    putchar('\n');

    show_char(' ', (len - strlen(sentence_2)) / 2);
    printf("%s",sentence_2);
    putchar('\n');

    show_char(' ', (len - strlen(sentence_3)) / 2);
    printf("%s",sentence_3);
    putchar('\n');
    putchar('\n');

    show_char('*', len);
    return 0;
}

void show_char(char ch, int num)
{
    for (int i = 0; i < num; i++)
    {
        putchar(ch);
    }
}