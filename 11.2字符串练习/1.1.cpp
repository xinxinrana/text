//输入并存储
#include <stdio.h>

int s_gets(char schar[], int size);
int main(int argc, char const *argv[])
{
    int size = 20;
    char chs[size+1];       //由于s_gets函数需要在最后一位添加‘\0’所以 size+1

    s_gets(chs, size);
    puts(chs);

    return 0;
}

//schar字符数组大小为 size+1！！最后一位是'\0'
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
