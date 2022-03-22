//结构体
#include <stdio.h>
#include <string.h>
#define MAXTITL 64
#define MAXAUTL 64

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int s_gets(char *schar, int size);
int main(int argc, char const *argv[])
{
    struct book library;

    printf("输入书籍名：\n");
    s_gets(library.title, MAXTITL);

    printf("输入作者：\n");
    s_gets(library.author, MAXAUTL);

    printf("价格：\n");
    while (scanf("%f", &library.value) != 1)
    {
        printf("你那是价格吗？\n");

        while (getchar() != '\n')
            continue;
    }

    printf("《%s》by %s 价格:%.2f \n", library.title, library.author, library.value);

    return 0;
}

//字符串get         //可用 size 为 （size —1）
int s_gets(char *schar, int size)
{
    int count = 0;

    // char temp;
    // bool clear_ed = false;
    // while(!clear_ed) //消除残留 \n 字符
    // {
    //     if ((temp = getchar()) != '\n')
    //     {
    //         schar[count] = temp;
    //         count++;
    //         clear_ed = true;
    //         break;
    //     }
    // }

    while ((count < size - 1) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size - 1)
    {
        schar[count] = '\0';
    }

    else
    {
        schar[count] = '\0';
        while (getchar() != '\n')
            continue;
    }

    return count;
}
