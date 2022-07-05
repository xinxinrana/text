//枚举  enum
#include <stdio.h>

int main(int argc, char const *argv[])
{
    enum spectrum
    {
        rad,
        orange,
        yrllow,
        green,
        blue,
        violet
    };
    const char *colors[] =
        {
            "rad",
            "orange",
            "yrllow",
            "green",
            "blue",
            "violet"};

    int color = rad;

    for (int i = 0; i < 6; i++)
    {
        printf("枚举类型的第%d个是:%d对应颜色是 %s\n", i, color,colors[i]);
        color++;
    }

    return 0;
}
