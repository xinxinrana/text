//输出
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int i=10;
    char chs[21];
    strcpy(chs,"🐮b");

    float i_2 = 2.1l;
    double i_3 = 2.31;
    char c = 'b';

    printf("格式输出：\n");
    printf("    i:%d\n",i);
    printf("    i_3:%lf\n",i_3);
    printf("    i_2:%f\n",i_2);
    printf("    chs:%s\n",chs);

    return 0;
}
