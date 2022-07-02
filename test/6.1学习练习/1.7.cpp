//等腰三角形
#include <stdio.h>

int main()
{

    char ch = 'R';

    for (int i = 0; i <= ch - 'A'; i++) // great
    {
        int j = (ch - 'A') - i;

        for (int x = j; x > 0; x--)
        {
            printf(" ");
        }

        for (int y = 0; y < i; y++)
        {
            char c = 'A' + y;
            printf("%c", c);
        }

        for (int y = 0; y <= i; y++)
        {
            char c = (ch - y) - j;
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
