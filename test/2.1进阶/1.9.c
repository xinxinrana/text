//结构体读取
#include<stdio.h>


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


int main(int argc, char const *argv[])
{
    int mondle_count = 4;
    modle modle_all[mondle_count];
    modle *modle_p = &modle_all[0];
    FILE *fp_r = fopen("xml结构体存储.bat","r+");       //打开失败
    int size_modle = sizeof(modle);

    for (int i = 0; i < mondle_count; i++)
    {
        fread(&modle_all[i],size_modle,1,fp_r);
    }

    for (int i = 0; i < mondle_count; i++)
    {
        printf(">>%10s ：%s\n", tabs[0], modle_all[i].name);
        printf(">>%10s ：%d\n", tabs[1], modle_all[i].age);
        printf(">>%10s ：%.2lf\n", tabs[2], modle_all[i].height);
        printf(">>%10s ：%s\n", tabs[3], modle_all[i].sc);
        printf(">>%10s ：%s\n", tabs[4], modle_all[i].yz);
        printf(">>>>\n");
    }
    


    return 0;
}
