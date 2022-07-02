// 分钟转小时or转秒
//要求：定义常量 使用while循环可多次使用
#include<stdio.h>
#define var1 60

int i=1;
double min=1 ;
int main()
{

    while(i)
    {
        printf(">>输入分钟，程序会输出对应的小时和秒钟：\n");
        scanf("%lf",&min );
        printf("%2.1lf分钟是%2.2lf小时\n",min,min/var1);
        printf("%2.1lf分钟是%2.0lf秒\n\n\n\n\n",min,min*var1);

        printf("如需退出请输入 0 \n\n");
        scanf("%d",&i);
    }
    
    return 0;
}
