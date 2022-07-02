//子函数中的指针的创建与泯灭
//子函数结束则结束，且无法retuen子函数中创建的地址
#include<stdio.h>

int P_P(void);
int main (void)
{
    int *p;
    P_P();
    printf("%p\n",p);

    return 0;
}

int P_P(void)
{
    int mar[2]={2,3};
    printf("%p\n",mar);
    // return mar;
    return 0;
}