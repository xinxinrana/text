// ctype.h字符函数
//更多测试
#include <stdio.h>
#include <ctype.h>

char To_Exchange(char i) //大小写互换，若非字母则不操作
{
    char exchanged = i;
    if (isalpha(i))
    {
        if (islower(i))
            exchanged = toupper(i);
        else
            exchanged = tolower(i);
        return exchanged;
    }
    else return i;
}

int main(void)
{
    char ch; //大小写互换
    ch = getchar();

    while (ch != '\n')
    {
        if (isalpha(ch))
            putchar(To_Exchange(ch));
        else
            putchar(ch);

        ch = getchar();
    }
    putchar(ch);
    return 0;

    // char i;      //控制字符检测
    // printf("put Cntrl!\n");
    // i = getchar();
    // if(iscntrl(i))
    //     printf("get Cntrl!");
    // else
    //     printf("get Nothing");
    // printf("\n\n");

    // char ch ;    //字母字符判断
    // ch = getchar();

    // while (ch != '\n')
    // {
    //     if (isalpha(ch))    putchar(ch+1);
    //     else                putchar(ch);

    //     ch = getchar();
    // }
    // putchar(ch);
    // return 0;
}
