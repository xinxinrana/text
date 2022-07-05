//取字符串函数
#include<stdio.h>
#include<stdbool.h>

//字符串get
int s_gets(char *schar, int size)
{
    int count = 0;

    char temp;
    bool clear_ed = false;
    for (int i = 1; i ==1;)         //消除残留 \n 字符
    {
        if((temp=getchar())!='\n')
        {
            schar[count] = temp;
            count++;
            clear_ed = true;
            break;
        }
    }
    
    while ((count < size) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size)
    {
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
