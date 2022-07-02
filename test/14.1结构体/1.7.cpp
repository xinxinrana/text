//动态分配
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINCHAR 32
#define MAXCHAR 128

struct text
{
    char *ch1;
    int id;
};


void putchar_s(const char ch,const int num);
void getinfo(struct text *t);
int s_gets(char *schar, const int size);
void cleanup(struct text *t);
int main(int argc, char const *argv[])
{
    struct text t1;
    getinfo(&t1);
    printf("%s,%d\n",t1.ch1,t1.id);
    printf("%zd,%zd,%zd",sizeof(t1.ch1),sizeof(t1.id),sizeof(*t1.ch1));
    //指向char的指针占 8 位   | int 占4位 | char 占1位  |
    cleanup(&t1);

    putchar_s('*',30);
    printf("%s,%d\n",t1.ch1,t1.id);
    printf("%zd,%zd,%zd",sizeof(t1.ch1),sizeof(t1.id),sizeof(*t1.ch1));

    return 0;
}

//字符串get         //可用 size 为 （size —1）
int s_gets(char *schar, const int size)
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

void getinfo(struct text *t)
{
    char temp[MINCHAR];
    puts("输入：\n");
    s_gets(temp, MINCHAR - 1);
    t->ch1 = (char*)malloc(strlen(temp)+1);
    strcpy(t->ch1,temp);
    puts("输入：\n");
    scanf("%d",&t->id);
    while(getchar()!='\n')
        continue;
}

void cleanup(struct text *t)
{
    free(t->ch1);
}

void putchar_s(const char ch,const int num)
{
    for (int i = 0; i < num; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}