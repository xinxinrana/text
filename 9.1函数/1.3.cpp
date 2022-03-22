//递归函数
//调用自己
#include<stdio.h>

void up_and_down(int n);
int main(void)
{
    up_and_down(1);
    return 0;
}

void up_and_down(int n)
{
    printf("level %d : n location %p \n",n,&n);     //#1

    if(n<4)
        up_and_down(n+1);
    
    printf("LEVEL %d : n location %p \n",n,&n);     //#2
}