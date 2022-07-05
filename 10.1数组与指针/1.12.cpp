//倒序数组中元素
#include <stdio.h>


void put_mar(int *array, int size);
void Reverse_order(int *array, int size);


int main(void)
{
    int size_1 = 10;
    int array_1[size_1] = {32, 43, 23, 53, 23, 13, 53, 45, 23, 25};

    put_mar(array_1,size_1);
    Reverse_order(array_1,size_1);
    put_mar(array_1,size_1);

    return 0;
}



void Reverse_order(int *array, int size)
{
    for (int i = 0; i  < size/2; i++)
    {
        array[i] = array[i] ^ array[size - i-1];
        array[size - i-1] = array[i] ^ array[size - i-1];
        array[i] = array[i] ^ array[size - i-1];
    }
}



void put_mar(int *array, int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("%4d ", array[j]);
    }
    putchar('\n');

}