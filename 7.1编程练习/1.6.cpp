//单词数量统计（伪）
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '|'
#define ENTER '\n'

int main()
{
    char ch;                 //接受字符位
    int Number_of_char = 0;  //字符数合计
    int Number_of_words = 0; //单词数合计
    int Number_of_rows = 1;  //行数合计
    bool In_word;            //读取状态-单词

    In_word = false;
    printf("输入一段英文，程序输出段落的字母数，单词数和行数\n");
    printf("结束字符为‘|’(英文状态)\n\n");
    while ((ch = getchar()) != STOP)
    {
        // putchar(ch);

        if (ch == ENTER)
        {
            Number_of_rows++;
        }

        if (isalpha(ch))
        {
            Number_of_char++;
        }

        if (isalpha(ch) && !In_word)
        {
            In_word = true;
            Number_of_words++;
        }

        if (!(isalpha(ch)) && In_word)
        {
            In_word = false;
        }
    }

    printf(":共%d个字符(不包括空白) 共%d个单词(伪)", Number_of_char, Number_of_words);
    printf("  %d行。\n\n", Number_of_rows);

    return 0;
}
