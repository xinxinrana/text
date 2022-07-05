// 字符串转换
#include <stdio.h>

int printf_center(const char *ch, const int all_width);
void putchar_s(const char c,const int n);

int main(int argc, char const *argv[])
{
    putchar_s('*',30);
    printf_center("\n", 30);



    return 0;
}

int printf_center(const char *ch, const int all_width)
{
    int ch_size = 0;
    int front_width;
    while (*(ch + ch_size))
    {
        ch_size++;
    }
    ch_size--;

    front_width = (all_width - ch_size) / 2;

    for (int i = 0; i < front_width; i++)
    {
        putchar(' ');
    }

    printf("%s", ch);
    return 0;
}

void putchar_s(const char c,const int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(c);
    }
    putchar('\n');
    
}



