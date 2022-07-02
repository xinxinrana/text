//指针函数
//将数组的每个数加 1
#include<stdio.h>
#include<string.h>
#define SIZE 10
#define PLUS 1

void plus_1 (int array[],int *array_end);

int main (void)
{
    int marbles[SIZE]={2,3,5,10,8,1,3,5,12,52};
    int *end =(marbles+SIZE);

    plus_1(marbles,end);

    putchar('\n');
    for (int i = 0; i < (sizeof(marbles))/(sizeof(marbles[0])); i++)
    {
        printf("%4d",marbles[i]);
    }
    

    return 0;
}

void plus_1 (int array[],int *array_end)
{
    for (int i = 0; array+i < array_end; ++i)
    {
        
        printf("%4d",array[i]+1);

        //对指定地址进行赋值，这个地址。
        //可以是来自实参，及直接对内存进行改变而无视子函数或主函数

        *(array+i) = *(array+i)+1;
    }
    
}