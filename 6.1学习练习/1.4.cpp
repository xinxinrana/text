//循环嵌套（已迭代）
//循环变式
#include <stdio.h>

int main()
{
    char ch;
    for (int i = 0; i < 26; i++)
    {
        for (ch = 'A'; ch <= 'A' + i; ch++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}
