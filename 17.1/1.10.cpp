//可变参数函数测试
#include<stdio.h>
#include <stdarg.h> //可变参函数头文件


double average(int num,...);

int main(int argc, char const *argv[])
{
    double aver_1 =  average(4, 4,7,3,5);
    double aver_2 =  average(10, 8,7,8,5,3,3,2,5,7,2);

    printf("%.6lf",aver_2);
    
    return 0;
}

double average(int num,...)
{
    va_list ap;
    double sum = 0;

    va_start(ap,num);
    for (int i = 0; i < num; i++)
    {
        sum +=va_arg(ap,int);
    }

    va_end(ap);
    
    return sum/num;
}
