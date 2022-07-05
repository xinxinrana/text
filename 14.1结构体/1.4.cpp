//结构体存储
#include <stdio.h>
#include <string.h>
#define MAXTITL 64
#define MAXAUTL 64
#define MAXBKS 24

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int s_gets(char *schar,const int size);
void putchar_s(const char ch,const int num);
int main(int argc, char const *argv[])
{
    int temp_scanf = 0;
    int count = 0;
    struct book library[MAXBKS];

    puts("请输入书籍名称: (按下回车后结束）");
    while ((s_gets(library[count].title, MAXTITL))&&(count<MAXBKS))
    {
        printf("\n请输入《%s》的作者 按下回车后结束\n", library[count].title);
        while (!(s_gets(library[count].author, MAXAUTL)))
        {
            puts("输入错误！请重新输入：");
        }

        printf("\n请输入《%s》的价格 按下回车后结束\n", library[count].title);

        temp_scanf = scanf("%f", &library[count].value);
        while(!temp_scanf)
        {
            while (getchar() != '\n')
                continue;
            puts("输入错误！请重新输入：");
            temp_scanf = scanf("%f", &library[count].value);  
        }

        while (getchar() != '\n')
                continue;

        putchar_s('\n',20);
        printf("%4s| %12s| %12s| %12s|","序号","书籍","作者","价格");
        for (int i = 0; i <= count; i++)
        {
            printf("\n%04d| %10s| %10s| %10.2f|"
            ,i+1,library[i].title,library[i].author,library[i].value);
        }
        
        count++;
        puts("\n\n继续输入书籍名 或按下回车退出：\n\n");
    }

    return 0;
}

//字符串get         //可用 size 为 （size —1）
int s_gets(char *schar,const int size)
{
    int count = 0;

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


void putchar_s(const char ch,const int num)
{
    for (int i = 0; i < num; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}