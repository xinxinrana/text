//数据类型
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char ch [20];
    printf("*%s*\n",ch);

    memset(ch, 0,sizeof(ch));
    printf("*%s*\n",ch);

    strcpy(ch,"中国");
    printf("*%s*\n",ch);

    return 0;
}
