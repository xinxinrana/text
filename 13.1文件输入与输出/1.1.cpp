//文件的读写
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int s_gets(char *schar, int size);
int main()
{
    FILE *fp;
    int c;
    int File_Name_size = 32;
    char File_Name[File_Name_size] = {"file.txt"};
    char file_w_temp;

    // puts("输入你要打开的文件名：");
    // s_gets(File_Name, File_Name_size);

    fp = fopen(File_Name, "r");
    while (1)
    {
        c = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);

    puts("是否需要更新其内容? Y/N");
    if (getchar() == 'Y')           //这里会残留 \n 导致后面getchar 接收到
    {

        fp = fopen(File_Name, "w");
        puts("请输入更新内容  按 ^z结束");
        while ((file_w_temp = getchar()) != '|')
                //         ^^           ^  = 优先级低于 != 这很重要！
        {
            putc(file_w_temp, fp);
        }
        fclose(fp);
    }

    puts("thanks!");
    return (0);
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

    while ((count < size-1) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size-1)
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
