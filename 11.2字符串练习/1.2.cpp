//统计（修改）字符串元素
#include <stdio.h>
#include <ctype.h>

void s_tolower(char *p);
void s_toupper(char *p);
int s_gets(char schar[], int size);
int main(int argc, char const *argv[])
{
    int size = 64;
    char chs_2[size];

    char chs_1[64] = {"I an Your F"};
    puts("s_tolower之后的");
    s_tolower(chs_1);
    puts(chs_1);putchar('\n');

    puts("s_toupper之后的");
    s_toupper(chs_1);
    puts(chs_1);

    s_gets(chs_2,size-1);
    s_toupper(chs_2);
    puts(chs_2);

    

    return 0;
}

//字符串全大写
void s_tolower(char *p)

{
    int count = 0;
    while ((p[count]) != '\0')
    {
        p[count] = tolower(p[count]);
        count++;
    }
}

//字符串全小写
void s_toupper(char *p)

{
    int count = 0;
    while ((p[count]) != '\0')
    {
        p[count] = toupper(p[count]);
        count++;
    }
}

//size —1后再给函数
int s_gets(char schar[], int size)
{
    int count = 0;
    while ((count < size) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size) {
        schar[count] = '\0';
        count--;
    }

    else
    {
        schar[count] = '\0';
        while (getchar() != '\n')
            continue;
    }

    return count;
}
