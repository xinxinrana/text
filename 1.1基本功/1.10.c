//循环简单
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int count = 100;
    for (int i = 0; i < count; i++)
    {
        if(!(i%5))
        {
            printf("%d是偶数\n",i);
        }
    }
    
    return 0;
}

