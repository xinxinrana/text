//变长数组  可定义数组长度（使用整形变量定义）
#include <stdio.h>

void put_mar(int, int, int mar[*][*]);
void N_and_1(int, int, int mar[*][*]);
int main(void)
{
    int rows = 3, clos = 4;

    int mar[rows][clos] = {
        {11, 14, 17, 19},
        {21, 24, 27, 29},
        {31, 34, 37, 39},
    };

    put_mar(rows, clos, mar);

    return 0;
}

void N_and_1(int r, int c, int mar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mar[i][j]++;
        }
    }
}

void put_mar(int r, int c, int mar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%4d ", mar[i][j]);
        }
        putchar('\n');
    }
}