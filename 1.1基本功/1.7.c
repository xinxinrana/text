// 1-100值的总和
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int target = 100;
    int sum = 0;

    for (int i = 0; i < (target + 1); i++)
    {
        sum = sum + i;
    }

    printf("从0到%d的总和是：%d\n",target,sum);

    return 0;
}
