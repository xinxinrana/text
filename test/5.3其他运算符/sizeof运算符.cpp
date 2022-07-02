#include<stdio.h>

int main()
{

    // int n = 0 ;
    // size_t munber;

    // munber= sizeof(int);
    // // printf("n = %d , n 的size:%zd  ,int的size:%zd\n\n\n",n,sizeof n,munber);


    // printf("这是一个字符串：%s","这是内容%s和\n\n\n");

    int i =97;
    while(i<=102)
    {
        printf("%c的ASCII码是:%d\n\n",(char)i,i);
        i++;
    }

    return 0;
}
