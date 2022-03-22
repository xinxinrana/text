//作用域
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int *p;
    for (; i < 5; i++)      //测试条件中 i 都是main局部变量！
    {
        printf("%d和%p\n",i,&i);

        int i = 3;
        printf("%d和%p\n",i,&i);        //块内的 i 都是局部变量！

        static int j = 5;
        printf("%d和%p\n",j,&j);
        p = &j;
    }

    //动态分配就是谁要给谁
    printf("\n%p  %d",&i+1,*((&i)+1));       //块一旦结束就被销毁了  可能是乱值 也可能每变化
    int s=9;
    printf("\n%p  %d",&s,s);
    printf("\n%p  %d",&i+1,*((&i)+1));      //新的变量自动存储在了局部变量不用的内存中

    //静态分配就是谁先来给谁，还能霸座 到终点才下车
    printf("\n%p  %d",p,*p);                //static 之后就是静态存储 外部可 间接调用
    (*p)++;
    printf("\n%p  %d",p,*p);                //静态是值内存分配静态 仍然可写可读

    
    return 0;
}
