//定义与声明  的冲突判定
#include <stdio.h>

int var = 100;

int max_n(const int i_0, const int i_1);

int main(int argc, char const *argv[])
{
    var = 20;
    int var_1 = 100;    

    printf("%d\n", max_n(2, 22));

    return 0;
}

int max_n(const int i_0, const int i_1)
{
    int temp = (i_0 > i_1) ? i_0 : i_1;
    return temp;
}
