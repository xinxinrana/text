// 字节数
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    printf("short int最大为：%.0lf  第占位是%4zd\n", pow(2, 8 * sizeof(short int)), sizeof(short int));
    printf("long double最大为：%.0lf  第占位是%4zd\n", pow(2, 8 * sizeof(long double)), sizeof(long double));
    printf("double最大为：%.0lf  f第占位是%4zd\n", pow(2, 8 * sizeof(double)), sizeof(double));
    printf("unsigned long最大为：%.0lf  第占位是%4zd,\n", pow(2, 8 * sizeof(unsigned long)), sizeof(unsigned long));
    printf("unsigned long long最大为：%.0lf  *第占位是%4zd\n", pow(2, 8 * sizeof(unsigned long long)), sizeof(unsigned long long));
    printf("long最大为：%.0lf 第占位是%4ld\n", pow(2, 8 * sizeof(long)), sizeof(long));

    unsigned int max = 1;
    unsigned int temp = 1;

    printf("%.0u\n", max);

    while (1)
    {
        temp = max * max + 1;
        if (!(temp < INFINITY))
        {
            break;
        }

        if (temp > max)
        {
            max = temp;
        }
        else
        {
            break;
        }
    }

    printf(" 最大值是%.0u", max);

    return 0;
}


// d s c f(e) u g p zd x           //g:在f和e 选择更短的
// h l ll  L
// - + 0                            //八进制输出是 'o'小写的 o  不是零
//#                                //# 进制模式带符号  浮点数模式带小数点
//数字A.数字B           