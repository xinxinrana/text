//scanf函数返回值
#include<stdio.h>

int i,j;

int main()
{
    printf("scanf函数返回值测试\n\n现在需要输入的类型是int");
    j = scanf("%d",&i);
    printf("i的值是%d\n",i);
    printf("%d\n\n",j);

    return 0;
}

//验证得出：如果用户输入值格式正确返回1 否则返回0