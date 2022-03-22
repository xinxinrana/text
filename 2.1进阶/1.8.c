// xml解析
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct model_s
{
    char name[32];
    int age;
    double height;
    char sc[32];
    char yz[32];
} modle;

const char tabs[5][32] = {
    {"name"},
    {"age"},
    {"height"},
    {"sc"},
    {"yz"},
};

int tab_to_num(char *ch);
void get_xml(FILE *file_p, char (*chs)[32]);
void write_to_struct(modle *modle_all, int tab_num, char *ch);
//变量多且乱  不利于维护
int main(int argc, char const *argv[])
{
    modle modle_all[4]; //结构体数组
    FILE *fp = fopen("xml解析.txt", "r");
    FILE *fp_w = fopen("xml结构体存储.bat", "w+");

    int tab_num = 0;      //临时标签
    int count = 30;       //循环查找次数
    char ch[2][32];       //临时存放xml
    int count_w = 0;      //临时计数跳转 辅助结构体指针位移
    int struct_count = 0; //结构体下标

    for (int i = 0; i < count; i++)
    {
        get_xml(fp, ch); // xml标签读取 一次一个
        if ((strlen(ch[0])) == 0)
            break; //读取为0则结束

        tab_num = tab_to_num(ch[0]); // tab 文字转换成标签号
        // printf("标签：%10s  内容：%s\n", ch[0], ch[1]);  //输出接收到的tab 和 内容

        write_to_struct(&modle_all[struct_count], tab_num, ch[1]); //写进结构体

        count_w++;
        if (count_w == 5)
        {
            struct_count++;
            count_w = 0;
        }
    }

    for (int i = 0; i < struct_count; i++)
    {
        printf(">>%10s ：%s\n", tabs[0], modle_all[i].name);
        printf(">>%10s ：%d\n", tabs[1], modle_all[i].age);
        printf(">>%10s ：%.2lf\n", tabs[2], modle_all[i].height);
        printf(">>%10s ：%s\n", tabs[3], modle_all[i].sc);
        printf(">>%10s ：%s\n", tabs[4], modle_all[i].yz);
        printf(">>>>\n");
    }
    fwrite(modle_all, sizeof(modle), struct_count, fp_w);

    fclose(fp);
    return 0;
}

void get_xml(FILE *file_p, char (*chs)[32])
{
    memset(chs[0], 0, 32);
    memset(chs[1], 0, 32);

    char temp = 0;
    char temp_chs[32];
    memset(temp_chs, 0, 32);
    int i = 0;
    bool get_tag = false;
    bool get_infor = false;
    bool file_state = true;

    while (file_state)
    {
        temp = getc(file_p);
        if (temp == EOF)
        {
            file_state = false;
            break;
        }
        if (temp == '<')
        {
            get_tag = true;
            temp = fgetc(file_p);
        }
        if (temp == '>')
        {
            get_tag = false;
            get_infor = true;
            break;
        }
        if (get_tag)
        {
            chs[0][i] = temp;
            i++;
        }
    }

    i = 0;

    while (file_state)
    {
        temp = fgetc(file_p);

        if (temp == EOF)
        {
            file_state = false;
            break;
        }

        if (temp == '<')
        {
            get_tag = true;
            get_infor = false;
            // fseek(file_p,-1,SEEK_CUR);
            break;
        }

        if (get_infor)
        {
            chs[1][i] = temp;
            i++;
        }
    }

    i = 0;
    while (file_state)
    {
        temp = fgetc(file_p);
        if (temp == EOF)
        {
            file_state = false;
            break;
        }
        if (temp == '/')
        {
            get_tag = true;
            temp = fgetc(file_p);
        }
        if (temp == '>')
        {
            get_tag = false;
            break;
        }
        if (get_tag)
        {
            temp_chs[i] = temp;
            i++;
        }
    }

    // if ((strcmp(chs[0], temp_chs)) == 0)
    // {
    //     // printf("get xml is great!");
    // }
    // else
    // {
    // memset(chs[0],0,32);
    // memset(chs[1],0,32);
    // }
}

//判断读取数据类型
int tab_to_num(char *ch)
{
    for (int j = 0; j < 5; j++) //判断读取数据类型
    {
        if ((strcmp(ch, tabs[j])) == 0)
        {
            return j;
        }
    }
    return -1;
}

//结构体写入数据
void write_to_struct(modle *modle_all, int tab_num, char *ch)
{
    switch (tab_num)
    {
    case 0:
        strcpy(modle_all->name, ch);
        break;
    case 1:
        modle_all->age = atoi(ch);
        break;
    case 2:
        modle_all->height = atof(ch);
        break;
    case 3:
        strcpy(modle_all->sc, ch);
        break;
    case 4:
        strcpy(modle_all->yz, ch);
        break;

    default:
        break;
    }
}
