//强制转换优先级
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i_1 = 7;
    int i_2 = 3;

    printf("%lf\n\n",(double)(i_1/i_2));        //2.000
    printf("%lf\n\n",(double)i_1/i_2);          //2.333
    //结论：强制转换高于计算运算；

    return 0;
}
