//文件的随即位置输出
//倒叙显示file.txt
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp_1;
    char ch;
    fp_1 = fopen("file.txt", "r");  //rb  r  在linux下无区别

    fseek(fp_1, 0l, SEEK_END);
    long count = ftell(fp_1);
    for (long i = 0; i < count; i++)
    {
        fseek(fp_1, -i, SEEK_END);
        ch = getc(fp_1);
        if (ch != '\032' && ch !='\r')
        {
            putchar(ch);
        }
    }

    return 0;
}
