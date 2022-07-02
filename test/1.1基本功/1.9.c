//九九乘法表
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int while_1=10;
    for (int i = 1; i < while_1; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            printf("%2d x %-2d= %-2d   ",j,i,i*j);
        }
        putchar('\n');
        
    }
    
    return 0;
}
