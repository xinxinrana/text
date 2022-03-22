//调试测试文件
#include<stdio.h>

int sum(int n1,int n2);

int main(int argc, char const *argv[])
{
    int num_1 = 0;
    int num_2 = 5;
    printf("这是第一条语句\n");

    printf("这是第二条语句\n");

    printf("num_1的值是：%d\n",num_1);
    printf("num_1+num_2的值是：%d\n",sum(num_1,num_2));

    ;

    return 0;
}

int sum(int n1,int n2)
{
    return n1+n2;
}
