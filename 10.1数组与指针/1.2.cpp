//数组与指针通用与不同
#include <stdio.h>
#define SIZE 10

int main(void)
{
    int marbles[SIZE] = {10, 9, 3, 4, 1};
    int *p = marbles;
    int i = 1;

    p++;
    printf("%20d", marbles[i]);
    printf("%20d",*(p));

    putchar('\n');putchar('\n');putchar('\n');

    printf("%20p", &marbles[i]);
    printf("%20p",p);

    return 0;
}

    // p 指向一个地址，可以是位置 0 处，也可能是其他某处
    //数组名 指向位置 0 处，且不可更改。指向其他就只能在[]中改变
    //且数组名[数] 表达的是 其中的值 非地址