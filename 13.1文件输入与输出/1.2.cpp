//创建一个文件并存放内容
#include <stdio.h>
#include <string.h>


int s_gets(char *schar, int size);
int main(int argc, char const *argv[])
{
    int name_size=16;
    char file_name[name_size];
    char file_w_temp;
    FILE *fp;

    puts("请输入创建文件的名称：\n");
    s_gets(file_name,name_size-6);
    strncat(file_name,".txt",5);

    fp = fopen(file_name,"w+");
    puts("请输入内容  输入： | 结束");
        while ((file_w_temp = getchar()) != '|')
        {
            putc(file_w_temp, fp);
        }
        fclose(fp);

    return 0;
}

//字符串get         //可用 size 为 （size —1）
int s_gets(char *schar, int size)
{
    int count = 0;

    char temp;
    bool clear_ed = false;
    for (int i = 1; i == 1;) //消除残留 \n 字符
    {
        if ((temp = getchar()) != '\n')
        {
            schar[count] = temp;
            count++;
            clear_ed = true;
            break;
        }
    }

    while ((count < size - 1) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size - 1)
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
