//***？***：***三位运算符
#include <stdio.h>
#include<ctype.h>

int main()
{
    int var_1, var_3;
    const int Divisor = 3;

    while (scanf("%d", &var_1) == 1)
    {
        var_3 = var_1 / Divisor;
        var_3 += ((var_1 % Divisor) == 0) ? 0 : 1;
        printf("%d / 3 = %d(上进位)", var_1, var_3);
    }

    return 0;
}
