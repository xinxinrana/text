//错误类型展示
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("错误类型：");
    int count = 135;
    for (int i = 0; i < count; i++)
    {
        errno = i;
        fprintf(stderr, "%3d  ", errno);
        perror(" ");
    }

    return 0;
}
