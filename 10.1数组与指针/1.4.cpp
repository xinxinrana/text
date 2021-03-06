//数组指针与独立的指针
//&**** 都是一个确定的地址，非左值，可以参与计算但不能参与赋值。
// p 是一个变量，类型为地址变量即指针，可以参与计算和赋值。
#include<stdio.h>

int main (void)
{
    int mar_1[] = {21,32,42,34,11,24,63};
    int *p_1 = &mar_1[1];
    int *p_2 ; 

    p_1++;
    // p_2 = ((&mar_1[1])++);       //报错原因：非左值接受了一个增量
    p_2 = (&mar_1[1+1]);

    printf("p_1的指针所指%p\n",p_1); 
    printf("p_2的指针所指%p\n",p_2); 
    return 0;
}