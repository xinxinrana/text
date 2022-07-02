//cpp的程序过渡
//引用
#include<stdio.h>


int swap(int &n1,int &n2);
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 30;

    swap(a,b);

    printf("a:%d   b:%d",a,b);
    
    return 0;
}

//引用作形参        //引用中的函数形参不能叫传递  叫调用，相当于把原始实参给函数处理
int swap(int &x,int &y)
{
    int temp;
    temp = x; /* 保存地址 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y  */

    return 0;
}
