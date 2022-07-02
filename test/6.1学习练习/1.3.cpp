//函数嵌套
//输出任意高底三角形
#include <stdio.h>
#include "math.h"

void printf_1(int i)
{
    while (i-- > 0)
        printf("*");
}

int h_to_w(int h, int high_1, int wide_1)
{
    int w;
    double high_2 = high_1;
    double wide_2 = wide_1 - 1; //三角形本质上是上底为1的梯形
    w = (h * (wide_2 / high_2)) + 1;
    return w;
}

void triangle(int high, int wide)
{
    printf("*\n");
    for (int i = 1; i <= high - 1; i++)
    {
        printf_1(h_to_w(i, high - 1, wide));
        printf("\n");
    }
}

int main()
{
    //输出指定高度和宽度的三角型
    float high = 0, wide = 0;

    printf("这个程序将会输出一个三角形\n");
    printf("输入三角形的底和高:\n");

    scanf("%f%f", &wide, &high);
    triangle(high, wide);

    return 0;
}
