//练习题
#include <stdio.h>

int Max_o(const double mar[], int num);
int main(void)
{
    int size_1 =10;
    double array_1[size_1]={32,43,23,53,23,13,53,45,23,25};
    printf("%s 最大差额是 %d\n","array_1",Max_o(array_1,size_1));
    return 0;
}

int Max_o(const double mar[], int num)
{
    int Max_order = 0;
    int Max = mar[0];
    int Min = mar[0];
    for (int i = 0; i < num; i++)
    {
        if (Max < mar[i])
        {
            Max = mar[i];
            Max_order = i+1;
        }

        if (Min > mar[i])
        {
            Min = mar[i];
        }
            
    }
    return (Max-Min);
}