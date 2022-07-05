//二进制io随机访问
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 64

int main(int argc, char const *argv[])
{
    double key_in[size];
    double temp;
    FILE *fp;
    int offset;
    char file_name[] = {"num.dat"};

    for (int i = 0; i < size; i++)
    {
        key_in[i] = (double)i;
    }

    if ((fp = fopen(file_name, "w+")) == NULL)
    {
        fprintf(stderr, "%s文件创建失败 ERR\n", file_name);
    }

    fwrite(key_in, sizeof(double), size, fp);

    puts("输入一个位置序号：(0-63之间)\n");
    while ((scanf("%d", &offset)) == 1)
    {
        if ((offset<0)||(offset>63))
        {
            fprintf(stderr,"\" %d \"位置输入错误",offset);
            exit(0);
        }
            
        fseek(fp, offset * sizeof(double), SEEK_SET);
        fread(&temp, sizeof(double), 1, fp);
        printf("在%d的double元素是:%lf\n", offset, temp);
    }

    return 0;
}
