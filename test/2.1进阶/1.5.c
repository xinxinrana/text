//错误列表输出 （中文）
//方式是文件调用
#include<stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("错误列表.txt","r+");
    char temp;

    while(1)
    {
        temp = fgetc(fp);
        if (temp==EOF)
        {
            break;
        }
        putchar(temp);
    }

    return 0;
}
