//浮点数对半
#include <stdio.h>

int main()
{
    float i = 10.0f;
    for (int j = 1; i > 0; i /= 2, j++)
    {
        printf("%3d  %14.6f\n", j, i);
    }

    return 0;
}
