//多文件外部链接 静态变量
#include<stdio.h>

void p_char_p(void)
{
    extern char ch_w;
    // extern char ch_n;       //这是1.2.cpp内部链接的变量 所以会报错
    printf("其他文件中函数调用ch_w:%4c\n\n",ch_w);
}