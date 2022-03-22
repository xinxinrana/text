//指针操作 const 
//指针的只读 是指针所指值只读，而指针本身是可写可读的
//且在嵌套在内部的指针也是可变的，const仅限制真实值
#include<stdio.h>

int main (void)
{
    const int marbles[10]={2,3,4,5};
    const int *p_a =&marbles[0];
    const int *p_b =&marbles[1];
    const int *p_c =&marbles[2];
    const int *p_d =&marbles[3];
    p_a++;
    const int *p_1[2] = {p_a,p_b};
    p_1[0] = p_c;

            //指针 p 被自增，却不会报错
    // (*p)++;   //这是会报错的    

    printf("%d",p_1[0][0]);
    return 0;
}