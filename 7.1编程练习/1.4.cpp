//求约数
#include <stdio.h>
#include <stdbool.h>

int main()
{
    long int var_1; //待测变量
    long int div_1;      //可能的约数
    bool prime;     //素数标记

    printf("程序可输出一个数的所有约数\n");
    printf("输入一个整数:");

    while (scanf("%ld", &var_1))
    {
        for (div_1 = 2, prime = true; (div_1 * div_1) <= var_1; div_1++)
        {
            if (var_1 < 2)
            {
                break;
            }
              
            if ((var_1 % div_1) == 0)
            {
                if ((div_1 * div_1) != var_1)
                {
                    printf("%5ld等于%3ld * %3ld\n", var_1, div_1, (var_1 / div_1));
                }
                else
                {
                    printf("%5ld是  %ld 的平方\n", var_1, div_1);
                }
                    
                prime = false;
            }
        }
        if (prime)
            printf("%5ld是一个素数。\n\n", var_1);
        printf("再次输入 or 输入非数字退出\n\n");
    }
    printf("再见！\n\n");

    return 0;
}
