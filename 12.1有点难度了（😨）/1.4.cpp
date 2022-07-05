//内存杀手🦐
#include<stdio.h>
#include<stdlib.h>

void kill_ram(int n);
int main(int argc, char const *argv[])
{
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 100; i++)
        {
            kill_ram(1024);
        }
    }
    
    
    
    
    return 0;
}

void kill_ram(int n)
{
    // void *temp;
    // temp = malloc(n*sizeof(int));  //申请静态 无链接 变量
    for (int i = 0; i < n; i++)
    {
        char ch[]={"你好"};
    }
    
    
}
