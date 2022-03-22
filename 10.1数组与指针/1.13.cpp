//数组copy
#include <stdio.h>

void array_copy(int *arr_1, int *arr_2, int size);
void array_copy_2( int size_1,int size_2,int (*arr_1)[4], int (*arr_2)[4]);
void put_mar(int *array, int size);
int main(void)
{

    int size_1 = 10;
    int array_1[size_1] = {32, 43, 23, 53, 23, 13, 53, 45, 23, 25};
    int array_2[size_1] = {0};
    int array_3[3][4] = {
        {11, 14, 17, 19},
        {21, 24, 27, 29},
        {31, 34, 37, 30},
    };
    int array_4[3][4]={0};
    int array_5[3]={0};

    array_copy_2(3,4,&array_3[0],&array_4[0]);

    for (int i = 0; i < 3; i++)
    {
        put_mar(array_4[i],4);
    }

    array_copy(array_1+2,array_5,3);
    put_mar(array_5,3);

    

    return 0;
}

void array_copy_2( int size_1,int size_2,int (*arr_1)[4], int (*arr_2)[4])
{
    for (int i = 0; i < size_1; i++)
    {
        array_copy(arr_1[i],arr_2[i],size_2);
    }
}

void array_copy(int *arr_1, int *arr_2, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr_2[i] = arr_1[i];
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