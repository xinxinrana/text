//打开不同文件并记录和存档
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void fcopy(FILE *fp_w, FILE *fp_r);
void fputchar_s(FILE *fp_r);
int s_gets(char *schar, int size);
void file_name_create(char *FileName);

int main(int argc, char const *argv[])
{
    char file_name_w[64];
    char file_name_r[64];
    FILE *fp_r, *fp_w;

    file_name_create(file_name_w);   //获取写文件的文件名（时间特征码）
    fp_w = fopen(file_name_w, "a+"); //打开写文件

    puts("输入你要打开的文件名：\n");      //获取文件名
    while ((s_gets(file_name_r, 63)) != 0) //循环获取文件名
    {

        fp_r = fopen(file_name_r, "r+"); //打开读文件
        if (fp_r == NULL)
        {
            exit(0);
        }
        fputchar_s(fp_r); //输出文件内容到 stdio

        fcopy(fp_w, fp_r); //拷贝文件到写文件
        puts("继续输入文件名或直接退出\n");
    }

    return 0;
}

//根据时间初始化文件名
void file_name_create(char *FileName)
{
    char file_name[64] = {"记录数据_"};
    time_t time_1;
    char time_id[4];

    time_1 = time(0);
    for (int i = 0; i < 3; i++)
    {
        time_id[i] = (time_1 % 10) + 48;
        time_id[i + 1] = '\0'; //自己创建的字符串记得手动填 '\0'
        time_1 /= 10;
    }

    strncat(file_name, time_id, 3);
    strncat(file_name, ".txt", 5);
    strncpy(FileName, file_name, 64);
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

//文件逐位拷贝      //缺点应嘎是效率不高  缓冲区加 指定位读取可能提高效率       
void fcopy(FILE *fp_w, FILE *fp_r)
{
    char ch_temp;
    fseek(fp_r, 0l, SEEK_SET);
    while ((ch_temp = getc(fp_r)) != EOF)
    {
        putc(ch_temp, fp_w);
    }
}
//文件建逐位输出到 stdio
void fputchar_s(FILE *fp_r)
{
    char ch_temp;
    while ((ch_temp = getc(fp_r)) != EOF)
    {
        putchar(ch_temp);
    }
}