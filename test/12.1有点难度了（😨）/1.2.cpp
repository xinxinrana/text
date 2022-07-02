//存储状态与链接
//静态 动态
//外部 内部 块
#include <stdio.h>

char ch_w = 'w';            //外部链接静态变量
static char ch_n = 'n';     //内部链接静态变量

void p_char(void);
void p_char_p(void);
int main(int argc, char const *argv[])
{
    extern char ch_w;
    extern char ch_n;
    printf("主函数调用ch_w和ch_n:%4c%4c\n\n",ch_w,ch_n);

    puts("\n非主函数:\n");
    p_char();

    puts("\n其他文件中调用:\n");
    p_char_p();
    return 0;
}

void p_char(void)
{
    extern char ch_w;
    extern char ch_n;
    printf("非主函数调用ch_w和ch_n:%4c%4c\n\n",ch_w,ch_n);
}
