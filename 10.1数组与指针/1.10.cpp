//练习题
#include <stdio.h>

int Max_int(const int mar[], int num);
int main(void)
{
    int size_1 =10;
    int array_1[size_1]={32,43,23,53,23,13,53,45,23,25};
    printf("%s  中最大的是 %d\n","array_1",Max_int(array_1,size_1));
    return 0;
}

int Max_int(const int mar[], int num)
{
    int Max = 0;
    for (int i = 0; i < num; i++)
    {
        if (Max < mar[i])
            Max = mar[i];
    }
    return Max;
}