//静态变量  自动存储变量  供动态分配内存的静态变量
#include <stdio.h>
#include<stdlib.h>

int var_1 = 0;
int main(int argc, char const *argv[])
{
    int *var_3;
    int var_2 = 0;
    var_3 = (int *) malloc(5*sizeof(int));

    printf("var_1的存储位置:%p\n\n",&var_1);
    printf("var_2的存储位置:%p\n\n",&var_2);
    printf("var_3的存储位置:%p\n\n",var_3);

    return 0;
}
