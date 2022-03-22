//两个文件进行合并编译测试
//linux ：gcc file_1 file_2
#include <stdio.h>

void d_to_bool(int i)
{
    int j;

    j = i % 2;
    if(i>1)
    d_to_bool(i / 2);
    putchar(j==0?'0':'1');
}
