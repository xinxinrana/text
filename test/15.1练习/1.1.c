// 指令 宏  
#include<stdio.h>
#include<stdlib.h>
// #include</usr/include/x86_64-linux-gnu/sys/cdefs.h>


void why_me(void);

int main(int argc, char const *argv[])
{
    printf("file:%s\n",__FILE__);
    printf("date:%s\n",__DATE__);
    printf("time:%s\n",__TIME__);
    printf("version:%d\n",__STDC__);
    printf("version:%ld\n",__STDC_VERSION__);
    printf("line:%d\n",__LINE__);
    printf("function:%s\n",__func__);


    why_me();

    return 0;
}

void why_me(void)
{
    printf("*****\n");
    printf("line:%d\n",__LINE__);
    printf("function:%s\n",__func__);
}