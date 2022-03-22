//pow 函数构建
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

unsigned int pow (const int in,const int po);
int main(int argc, char const *argv[])
{

    printf("0的0次方是：%u",pow(0,0));
    
    return 0;
}


unsigned int pow (const int in,const int po)
{
    if (po==0)
    {
        if (in!=0)
        {
            return 1;
        }
        else
        {
            errno = 1;
            perror("参数错误");
            exit(0);
        }
    }
    
    int temp = in;
    for (int i = 1; i < po; i++)
    {
        temp = temp *in;
    }

    return temp;
    
}